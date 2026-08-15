# <c-5DEBFF>G</c><c-68DEFF>l</c><c-75D0FF>o</c><c-84C2FF>b</c><c-95B3FF>a</c><c-A8A3FF>l</c> <c-B994FF>D</c><c-CA84F7>e</c><c-DB75EE>m</c><c-E967DF>o</c><c-F45FCB>n</c><c-FB61B3>l</c><c-FF6997>i</c><c-FF777C>s</c><c-FF8964>t</c> <c-FFA34F>R</c><c-FFBD49>a</c><c-FFD44C>n</c><c-FFEA5A>k</c> <cg>v1.1.1</c>

### <c-66E6FF>See a level's current Global Demonlist placement directly in Geometry Dash.</c>

---

## <c-5DEBFF>WHAT IT DOES</c>

When you open a classic level, the mod looks up its Geometry Dash ID using the public [Global Demonlist API](https://demonlist.org/api-docs).

- <c-FFD65A>**Listed level:**</c> displays `Global #<placement>` below the difficulty and star information.
- <c-74E8FF>**Unlisted level:**</c> leaves the level page unchanged.
- <c-C59BFF>**Connection unavailable:**</c> leaves the page usable without blocking the game.

## <c-8DDCFF>FAST AND UNOBTRUSIVE</c>

Requests run <cg>asynchronously</c>, so the game does not wait for the network. Placements are cached until Geometry Dash restarts to avoid requesting the same level repeatedly.

The label is positioned <c-FFD65A>below the star row</c>, so it does not cover the star count or icon.

## <c-D79BFF>SETTINGS</c>

Use the <cy>Show Global Rank</c> setting to enable or disable the placement label.

---

<c-AEDBFF>Placement data:</c> [Global Demonlist](https://demonlist.org/)

<c-C9B3FF>API documentation:</c> [demonlist.org/api-docs](https://demonlist.org/api-docs)

<c-FFD65A>Developer:</c> **BANANCHIKIREAL**
