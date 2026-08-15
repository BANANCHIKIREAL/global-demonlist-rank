# Global Demonlist Rank

Shows the current Global Demonlist placement directly below the difficulty icon on the level information screen.

The mod uses the public read-only Global Demonlist API. Requests are asynchronous and use the Geometry Dash level ID. Listed levels display `Global #<placement>`; unlisted levels are left unchanged.

Placements are cached for the current game session to avoid repeated requests when reopening the same level. Restarting Geometry Dash refreshes the session cache.

Data source: [demonlist.org](https://demonlist.org/)
