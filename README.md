# Global Demonlist Rank

Geode-мод для Geometry Dash 2.2081, который показывает актуальное место уровня в [Global Demonlist](https://demonlist.org/) прямо под значком сложности на странице уровня.

Мод отправляет асинхронный GET-запрос к публичному endpoint:

`https://api.demonlist.org/level/classic/get?ingame_id=<LEVEL_ID>`

Если уровень найден, отображается надпись `Global #<место>`. Если уровня нет в списке или соединение недоступно, интерфейс Geometry Dash остаётся без изменений.

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
