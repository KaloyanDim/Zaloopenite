# HackTues9 
## Kitsune and DuckySlayer project
### Made by team Zaloopenite

Повечето хора в днешно време знаят, че не трябва да включват в компютрите си флашки от несигурни източници. Но колко всъщност са се замисляли за зловредни HID (Human interface devices) устройства? Нашият проект е свързан точно с такива пропуски в сигурността. 

## Използвани части
1. USB мишка
Това ще е прикритието на семействието от платки и елементи, за да се възползват от липсата на внимание около различните видове HID атаки.
2. ESP 32 Devkit
С ESP32 DEVKIT слушаме за натискането на един бутон в локално хостнатия сървър, както и за управлението ни широк спектър от пинове. Така управляваме релетата.
3. Реле модул
Както казахме, релетата са управлявани от ESP32 за да променят собственикът на USB връзката, чрез превключването на мрежата на DATA- от тази идваща от кабела и точките за достъп на USB мишката и Raspberry pi pico. Така се избира, кога започва атаката чрез keylogging or keystroke injection.
4. Raspberry Pi Pico
Оригиналното Rubber Ducky е USB флашка, която се представя на богатите инвестори

## Цели на проекта
1. Създаване на keystroke injection атаки
2. Правантивен софтуер за този вид атаки
3. Свързване със сървър, който позволява на потребителя да атакува замаскираното като HID устройство, Raspberry Pi Pico.

