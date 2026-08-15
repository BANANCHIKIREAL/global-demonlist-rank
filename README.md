# Global Demonlist Rank

Geode-мод для Geometry Dash 2.2081, который показывает актуальное место уровня в [Global Demonlist](https://demonlist.org/) ниже блока сложности и звёзд на странице уровня.

Мод отправляет асинхронный GET-запрос к публичному endpoint:

`https://api.demonlist.org/level/classic/get?ingame_id=<LEVEL_ID>`

Если уровень найден, отображается кубок Geometry Dash и номер позиции штатным золотым шрифтом игры. Благодаря этому текстурпаки могут корректно заменять его. Чем выше уровень находится в рейтинге, тем престижнее вариант кубка; `#1` получает лучший. Если уровня нет в списке, дополнительный блок не показывается.

Во время запроса отображается индикатор загрузки. При ошибке сети появляется красный крестик, который плавно исчезает.

Версия v1.2.0 совместима с IngameListMod: Global Demonlist располагается отдельной компактной строкой ниже его AREDL-позиции. Подпись `GLOBAL` больше не влияет на центрирование кубка и числа, а без IngameListMod строка учитывает все видимые монеты уровня. Также сохранены толстая рамка с прозрачными углами и англоязычное градиентное описание внутри Geode.

## API для других модов

Публичный заголовок `include/GlobalDemonlistRankAPI.hpp` входит в пакет `.geode`. Он предоставляет:

- `getCachedPlacement(levelID)` для чтения последнего состояния;
- `PlacementUpdateEvent` для получения обновлений;
- состояния `Loading`, `Listed`, `Unlisted` и `Error`;
- номер позиции в `PlacementResult::placement` для состояния `Listed`.

```cpp
#include <GlobalDemonlistRankAPI.hpp>

using namespace bananchikireal::global_demonlist_rank;

auto listener = PlacementUpdateEvent().listen([](PlacementResult const& result) {
    if (result.state == PlacementState::Listed && result.placement) {
        geode::log::info("Level {} is Global #{}", result.levelID, *result.placement);
    }
    return geode::ListenerResult::Propagate;
});
```

## Сборка

Требования:

- Geometry Dash 2.2081;
- Geode SDK 5.9.0;
- Geode CLI;
- CMake 3.21 или новее;
- компилятор с поддержкой C++23.

```powershell
geode build --platform windows --config Release
```

Готовый пакет появится в папке `build`.

## Источники данных

- [Global Demonlist](https://demonlist.org/)
- [Global Demonlist API documentation](https://api.demonlist.org/docs)

## Лицензия

MIT — см. [LICENSE](LICENSE).
