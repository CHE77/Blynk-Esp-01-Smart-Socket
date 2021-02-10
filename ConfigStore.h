/**************************************************************
 * This is a DEMO. You can use it only for development and testing.
 *
 * If you would like to add these features to your product,
 * please contact Blynk for Business:
 *
 *                  http://www.blynk.io/
 *
 **************************************************************/

struct ConfigStore {
  uint32_t  magic;
  char      version[9];
  uint8_t   flagConfig:1;
  uint8_t   flagApFail:1;
  uint8_t   flagSelfTest:1;

  char      wifiSSID[34];
  char      wifiPass[64];

  char      cloudToken[34];
  char      cloudHost[34];
  uint16_t  cloudPort;
   char      clouddevice_name[64]; ///

  uint16_t  checksum;
} __attribute__((packed));

ConfigStore configStore;

const ConfigStore configDefault = {
  0x626C6E6B,
  BOARD_FIRMWARE_VERSION,
  0, // change to 1 to use config after boot
  0, 0,
  
  "",// Wi-Fi SSID можно уже ввести по умолчанию (между "")
  "",// Wi-Fi password можно уже ввести по умолчанию
  
  "invalid token", // blynk token можно уже ввести по умолчанию
  "blynk-cloud.com", 80,
  "Умное устройство",/// можно уже ввести по умолчанию
  0
};

#include <EEPROM.h>
#define EEPROM_CONFIG_START 0

void config_load()
{
  memset(&configStore, 0, sizeof(configStore));
  EEPROM.get(EEPROM_CONFIG_START, configStore);
  if (configStore.magic != configDefault.magic) {
    DEBUG_PRINT("Using default config.");
    configStore = configDefault;
    return;
  }
}

bool config_save()
{
  EEPROM.put(EEPROM_CONFIG_START, configStore);
  EEPROM.commit();
  return true;
}

bool config_init()
{
  EEPROM.begin(sizeof(ConfigStore));
  config_load();
  return true;
}

void enterResetConfig()
{
  DEBUG_PRINT("Resetting configuration!");
  configStore = configDefault;
  config_save();
  BlynkState::set(MODE_WAIT_CONFIG);
}

template<typename T, int size>
void CopyString(const String& s, T(&arr)[size]) {
  s.toCharArray(arr, size);
}
