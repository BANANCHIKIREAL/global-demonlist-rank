# v1.1.2

- Made all four outer icon corners genuinely transparent.
- Increased the blue frame thickness while preserving the supplied demon artwork.
- Added a loading spinner while the Global Demonlist request is in progress.
- Added a fading red cross when the request fails because the service or network is unavailable.
- Replaced the plain `Global #...` text with a built-in Geometry Dash trophy and a large purple placement number.
- Added automatic trophy tiers for #1, top 10, top 50, top 100, and progressively lower placement ranges.

# v1.1.1

- Replaced the in-Geode Russian description with English text supported by the default Geode font.
- Increased the icon frame radius and stroke width so the rounded blue border remains visible at Geode thumbnail size.

# v1.1.0

- Fixed the Global Demonlist label overlapping the level's star count and star icon.
- Positioned the label below the complete difficulty and star information block.
- Reduced the label size for better readability and compatibility with texture packs.
- Added a rounded blue edge frame to the user-supplied mod icon without altering its central artwork.
- Added a detailed in-Geode description with a cyan, purple, and gold gradient.

# v1.0.0

- Added Global Demonlist placement below the level difficulty icon.
- Added asynchronous lookups by Geometry Dash level ID through the public Global Demonlist API.
- Added session caching for successful and confirmed unlisted lookups.
- Added graceful handling for unavailable, malformed, and not-found API responses.
- Added an option to enable or disable the placement label.
