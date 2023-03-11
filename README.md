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
Оригиналното Rubber Ducky е USB флашка, която се представя за HID, а по-точно като калвиатура, поради един важен факт. Клавиатурата е много интимно свързана с компютъра и за това системата има много доверие и не пита въпроси към клавиатури. Те са единствения начин за input при много трудни сценарии и обстановки. Понеже за да променим firmware-а на нашата флашка, тя трябва да има един специфичен чипсет, който не се произвежда от години, на нас ни се наложи да използваме Raspberry Pi Pico. Taka raspberry-то се представя за USB флашка, а след това тази "флашка" се представя за клавиатура за да се възползваме от разликата в привилегии на устройствата. Чрез python превеждащ слой, ще можем да използваме езика DucckyScript и да пишем по-лесно скриптове, които се съдържат в payload.dd . 

## Цели на проекта
1. Създаване на keystroke injection атаки
Поставихме си за цел, да успеем във важния сектор Physical/Port Security за да можем да покажем на младите ученици, колко опасни и лесни атаки могат да ни навредят.
2. Превантивен софтуер за този вид атаки
Освен реализиране на breach софтуера и неговите ниско-морални цели и възможности, ние създадохме background dweller програма, която за задача има да заключи Windows-а при включването на ново USB устройство. Така когато си свържем фалшивата клавиатура, Windows ще бъде локнат и скрипта ще се изпрати в полето за парола, правейки го неефективен за атакуване. Така можем да се предпазим от този тип скрита флашка...  
3. Свързване със сървър, който позволява на потребителя да атакува замаскираното като HID устройство, Raspberry Pi Pico, в удобен момент.
Има node.js сървър, който използва модула express. В html файла има порция с tag-а <script>, в който има просто javascript за да се променят картината на сайта, както и цвета на част от текста. При натискане на бутона се извиква функция, която изпълнява XML услуга. ESP31 DEVKIT-a когато получава request за натиснатия бутон, превключва един от двата DATA сигнала от USB кабела. От началното устройство мишка до "клавиатурата" ни на Razpberry Pi Pico платформата.
