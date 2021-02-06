/*************************************************************
  This is a DEMO. You can use it only for development and testing.
  You should open Setting.h and modify General options.

  If you would like to add these features to your product,
  please contact Blynk for Businesses:

                   http://www.blynk.io/

  в Блинк добавляем виджет Button на пин где реле

 *************************************************************/

//#define USE_SPARKFUN_BLYNK_BOARD    // Uncomment the board you are using
//#define USE_NODE_MCU_BOARD        // Comment out the boards you are not using
//#define USE_WITTY_CLOUD_BOARD
#define USE_CUSTOM_BOARD          // For all other ESP8266-based boards -
// see "Custom board configuration" in Settings.h

#define APP_DEBUG        // Comment this out to disable debug prints

#define BLYNK_PRINT Serial

#include "BlynkProvisioning.h"

#include <ArduinoOTA.h>///

BlynkTimer timer;

int relayPin = 0;//

bool isFirstConnect = true;





// Синхронизация при конекте
BLYNK_CONNECTED() {
  if (isFirstConnect) {
    Blynk.syncAll();   timer.setTimeout(2000, [] {
      String currentTime = String(hour()) + ":" + minute() + ":" + second();
      String currentDate = String(day()) + "/" + month() + "/" + year() + " ";
      String Notif = "Умное Устройство Запущено  " + currentTime + " " + currentDate;
      Blynk.notify(Notif);
    }                                  );
    isFirstConnect = false;
  }
}



void setup() {


  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // set LED OFF
  rtc.begin();
  delay(500);
  Serial.begin(9600);// надо закомментировать чтобы заработала индикация хода подкючения на BOARD_LED_PIN

  BlynkProvisioning.begin();

  ArduinoOTA.begin();// для прошивки по вай-фай прямо из Arduiino IDE

  timer.setInterval(1000, blinkV0);///только для проверки соединия с серверовм. В приложении выставить Value Display виджет на V0

  Serial.println("end of setup");

}

void loop() {
  // This handles the network and cloud connection
  ArduinoOTA.handle();
  BlynkProvisioning.run();
  timer.run(); // Запускаем таймер

}

// фукнкция для проверки наличия подключения к Blynk
void blinkV0() {
  Blynk.virtualWrite(V0, millis() / 1000);
  Serial.println(millis() / 1000);
}
