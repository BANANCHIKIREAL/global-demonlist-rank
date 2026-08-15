#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/utils/web.hpp>

#include <chrono>
#include <optional>
#include <unordered_map>

using namespace geode::prelude;

namespace {
constexpr char const* API_URL = "https://api.demonlist.org/level/classic/get";
constexpr char const* USER_AGENT = "BANANCHIKIREAL-GlobalDemonlistRank/1.0";

// A null rank means that the API confirmed this level is not on the list.
// The cache lives only for the current game session, so placements are refreshed
// after restarting Geometry Dash.
std::unordered_map<int, std::optional<int>> g_rankCache;

std::optional<int> parsePlacement(web::WebResponse const& response) {
    auto json = response.json();
    if (!json.isOk()) {
        return std::nullopt;
    }

    auto& root = json.unwrap();
    auto message = root.get<std::string>("message");
    if (!message.isOk() || message.unwrap() != "success") {
        return std::nullopt;
    }

    auto data = root.get("data");
    if (!data.isOk()) {
        return std::nullopt;
    }

    auto placement = data.unwrap().get<int>("placement");
    if (!placement.isOk() || placement.unwrap() < 1) {
        return std::nullopt;
    }

    return placement.unwrap();
}
}

class $modify(GlobalDemonlistRankLevelInfoLayer, LevelInfoLayer) {
    struct Fields {
        TaskHolder<web::WebResponse> request;
        CCLabelBMFont* label = nullptr;
        int levelID = 0;
    };

    void showPlacement(int placement) {
        if (!m_fields->label) {
            return;
        }

        m_fields->label->setString(fmt::format("Global #{}", placement).c_str());
        m_fields->label->setVisible(true);
    }

    void addPlacementLabel() {
        if (!m_difficultySprite || !m_difficultySprite->getParent()) {
            return;
        }

        auto parent = m_difficultySprite->getParent();
        auto label = CCLabelBMFont::create("", "goldFont.fnt");
        label->setID("global-demonlist-rank-label"_spr);
        label->setScale(.42f);
        label->setVisible(false);

        auto const difficultySize = m_difficultySprite->getScaledContentSize();
        label->setPosition({
            m_difficultySprite->getPositionX(),
            m_difficultySprite->getPositionY() - difficultySize.height / 2.f - 7.f,
        });

        parent->addChild(label, m_difficultySprite->getZOrder() + 1);
        m_fields->label = label;
    }

    void requestPlacement() {
        auto const levelID = m_fields->levelID;
        if (levelID <= 0) {
            return;
        }

        if (auto cached = g_rankCache.find(levelID); cached != g_rankCache.end()) {
            if (cached->second.has_value()) {
                showPlacement(*cached->second);
            }
            return;
        }

        auto request = web::WebRequest();
        request
            .header("Accept", "application/json")
            .userAgent(USER_AGENT)
            .timeout(std::chrono::seconds(10));

        auto const url = fmt::format("{}?ingame_id={}", API_URL, levelID);
        m_fields->request.spawn(request.get(url), [this, levelID](web::WebResponse response) {
            // The callback is owned by TaskHolder and is cancelled with this layer.
            if (m_fields->levelID != levelID) {
                return;
            }

            if (response.code() == 404) {
                g_rankCache.insert_or_assign(levelID, std::nullopt);
                return;
            }

            if (!response.ok()) {
                log::warn(
                    "Global Demonlist request for level {} failed with HTTP {}: {}",
                    levelID,
                    response.code(),
                    response.errorMessage()
                );
                return;
            }

            auto placement = parsePlacement(response);
            if (!placement.has_value()) {
                log::warn("Global Demonlist returned an unexpected response for level {}", levelID);
                return;
            }

            g_rankCache.insert_or_assign(levelID, placement);
            showPlacement(*placement);
        });
    }

    bool init(GJGameLevel* level, bool challenge) {
        if (!LevelInfoLayer::init(level, challenge)) {
            return false;
        }

        if (!level || !Mod::get()->getSettingValue<bool>("enabled")) {
            return true;
        }

        // The Global Demonlist classic endpoint does not rank platformer levels.
        if (level->isPlatformer()) {
            return true;
        }

        m_fields->levelID = static_cast<int>(level->m_levelID);
        if (m_fields->levelID <= 0) {
            return true;
        }

        addPlacementLabel();
        requestPlacement();
        return true;
    }
};
