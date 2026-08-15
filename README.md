# Global Demonlist Rank

Geode-мод для Geometry Dash 2.2081, который показывает актуальное место уровня в [Global Demonlist](https://demonlist.org/) ниже блока сложности и звёзд на странице уровня.

Мод отправляет асинхронный GET-запрос к публичному endpoint:

`https://api.demonlist.org/level/classic/get?ingame_id=<LEVEL_ID>`

Если уровень найден, отображается кубок Geometry Dash и крупный фиолетовый номер позиции. Чем выше уровень находится в рейтинге, тем престижнее вариант кубка; `#1` получает лучший. Если уровня нет в списке, дополнительный блок не показывается.

Во время запроса отображается индикатор загрузки. При ошибке сети появляется красный крестик, который плавно исчезает.

Версия v1.1.2 исправляет наложение позиции на количество звёзд, добавляет толстую округлую рамку с прозрачными углами и англоязычное градиентное описание внутри Geode.

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
