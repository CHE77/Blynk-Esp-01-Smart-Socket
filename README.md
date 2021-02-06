# Blynk-Esp-01-Smart-Socket
Умная розетка на Esp-01 и приложении Blynk

Такому модулю нужна небольшая переделка.


![alt text](https://github.com/CHE77/Blynk-Esp-01-Smart-Socket/blob/main/ESP01-S-5V-WiFi-Relay-Module1.jpg?raw=true)

Нужно выпаять или выломать резистор R2. Иначе реле может не влючаться.




![alt text](https://github.com/CHE77/Blynk-Esp-01-Smart-Socket/blob/main/esp8266-01s-relay-expansion-module-back1.jpg?raw=true)

C другой стороны надо добывать перемычку мужду VCC и CH_PD. Иначе контролер может не загрузиться.
