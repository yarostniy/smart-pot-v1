# Прошивка для умного горшка на базе ESP32 и датчика влажности. V1 (Первая версия)

Это первая версия прошивки включает в себя самый простой функционал.

- Неиспользуется delay, все сделано на базе Timer
- Режим экономии энергии
- Свтовая сигнализация о необходимости полива

Каждые 3600 секунд процессор считывает данные с датчика влажности, если влажность в норме, то он уходит в глубокий сон на 3600-1 секунд. Можно увеличить время на свое усмотрение, например на 3 часа.
Если влажность меньше требуемой, то светододиод будет мигать пока вы не польете растение.

- Настройка производится в файле /lib/ConfigDevice/ConfigDevice.h

# Установка и сборка.

- Клонируйте репозиторий
- Откройте папку с склонированным репозиторием в редакторе VSCode с установленным в нем плагином Platformio (В ютуб много инструкций как установить Platformio)
- Подключите свое устройство к USB и залейте прошивку

# Компоненты для сборки

- Датчик влажности https://aliexpress.ru/item/32906088820.html?spm=a2g0s.9042311.0.0.59b333edUFllkM
- Основная плата ESP-32S ESP-WROOM-32 https://aliexpress.ru/item/32864722159.html?spm=a2g0s.9042311.0.0.264d33ed34J9ue
- Макетная доска 1 https://aliexpress.ru/item/850064380.html?spm=a2g0s.9042311.0.0.264d33ed34J9ue
- Макетная доска 2 https://aliexpress.ru/item/32712592859.html?spm=a2g0s.9042311.0.0.264d33ed51p8BY
- Аккумулятор https://aliexpress.ru/item/32862730111.html?spm=a2g0s.9042311.0.0.264d33ed34J9ue
- USB зарядное устройство для аккумулятора https://aliexpress.ru/item/32649780468.html?spm=a2g0s.9042311.0.0.264d33ed51p8BY

Все это можно собрать используя только датчик влажности, основную плату, светодиод и кабель USB.

![Схема подключения](https://github.com/yarostniy/smart-pot-v1/blob/master/schema.png)
