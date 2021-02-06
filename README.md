# Blynk-Esp-01-Smart-Socket
Умная розетка на Esp-01 и приложении Blynk на примере реле-модуля


Устанавливаем приложение Blynk на телефон/планшет.
https://play.google.com/store/apps/details?id=cc.blynk&hl=ru&gl=US
Создаем новый проект и высылаем токен Blynk себе на почту
В проекте добавляем виджет кнопки. Указываем пин 0.
Можно еще довавить виджет Value Display и указать Virtual Pin - V0. 

Скачиваем все файлы из проекта.

Открываем (файл *.ino) на Arduino IDE https://www.arduino.cc/en/software
Заливаем скетч на контролер
Подключаем контролер к модулю реле.

Скетч запускаетWi-Fi точку доступа "Umnоe_Ustroystvo"
Подключаемся к ней. Если не откроется браузер, идем в него сами и вбиваем адрес http://192.168.4.1/
На странице вводим название своей домашней точки доступа Wi-Fi, ее пароль и токен Blynk.
Сохраняем. Контролер перезагрузится и подключится к Wi-Fi и облаку Blynk.


Такому модулю нужна небольшая переделка.


![alt text](https://github.com/CHE77/Blynk-Esp-01-Smart-Socket/blob/main/ESP01-S-5V-WiFi-Relay-Module1.jpg?raw=true)

Нужно выпаять или выломать резистор R2. Иначе реле может не влючаться.




![alt text](https://github.com/CHE77/Blynk-Esp-01-Smart-Socket/blob/main/esp8266-01s-relay-expansion-module-back1.jpg?raw=true)

C другой стороны надо добывать перемычку мужду VCC и CH_PD. Иначе контролер может не загрузиться.
