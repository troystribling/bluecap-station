#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include "hello_world_peripheral.h"
#include "utils.h"
#include "services.h"
#include "byte_swap.h"

#define GREETING_COUNT                12
#define INITIAL_UPDATE_PERIOD         5000
#define INVALID_UPDATE_PERIOD_ERROR   0x80
#define MIN_UPDATE_PERIOD             200
#define MAX_UPDATE_PERIOD             10000

static services_pipe_type_mapping_t services_pipe_type_mapping[NUMBER_OF_PIPES] = SERVICES_PIPE_TYPE_MAPPING_CONTENT;
static hal_aci_data_t setup_msgs[NB_SETUP_MESSAGES] PROGMEM = SETUP_MESSAGES_CONTENT;

static char* greetings[] = {
  "Hello",
  "Aloha",
  "Moin",
  "Sveiki",
  "Moin",
  "Salut",
  "Hola",
  "Ciao",
  "nuqneH",
  "Bonjour",
  "Hej",
  "Molim"
};

static uint16_t updatePeriod;
static unsigned char greetingIndex = 0;
static uint16_t statusAddress = 0;
static uint16_t updatePeriodAddress = 2;

static uint8_t  batteryLevel = 100;

HelloWorldPeripheral::HelloWorldPeripheral(uint8_t reqn, uint8_t rdyn): BlueCapPeripheral(reqn, rdyn) {
  setServicePipeTypeMapping(services_pipe_type_mapping, NUMBER_OF_PIPES);
  setSetUpMessages(setup_msgs, NB_SETUP_MESSAGES);
  deviceBatteryLevelInitial = -1.0;
}

void HelloWorldPeripheral::didReceiveData(uint8_t characteristicId, uint8_t* data, uint8_t size) {
  switch(characteristicId) {
    case PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK:
      setUpdatePeriod(data, size);
      break;
    default:
      break;
  }
}

void HelloWorldPeripheral::didReceiveCommandResponse(uint8_t commandId, uint8_t* data, uint8_t size) {
  switch(commandId) {
    case ACI_CMD_GET_BATTERY_LEVEL:
      INFO_LOG(F("ACI_CMD_GET_BATTERY_LEVEL response received"));
      setBatteryLevel(data, size);
      break;
    case ACI_CMD_GET_TEMPERATURE:
      INFO_LOG(F("ACI_CMD_GET_TEMPERATURE response received"));
      setTemperature(data, size);
      break;
    case ACI_CMD_CONNECT:
      INFO_LOG(F("ACI_CMD_CONNECT response received"));
      break;
    case ACI_CMD_GET_DEVICE_ADDRESS:
      INFO_LOG(F("ACI_CMD_GET_DEVICE_ADDRESS response received"));
      setBLEAddress(data, size);
      break;
    case ACI_CMD_GET_DEVICE_VERSION:
      INFO_LOG(F("ACI_CMD_GET_DEVICE_VERSION response received"));
      break;
    case  ACI_CMD_SET_LOCAL_DATA:
      INFO_LOG(F("ACI_CMD_SET_LOCAL_DATA response received"));
      break;
    case ACI_CMD_SEND_DATA:
      INFO_LOG(F("ACI_CMD_SEND_DATA response received"));
      break;
    case ACI_CMD_SEND_DATA_ACK:
      INFO_LOG(F("ACI_CMD_SEND_DATA_ACK response received"));
      break;
    case ACI_CMD_SEND_DATA_NACK:
      INFO_LOG(F("ACI_CMD_SEND_DATA_NACK response received"));
      break;
    case ACI_CMD_CHANGE_TIMING:
      INFO_LOG(F("ACI_CMD_CHANGE_TIMING response received"));
      break;
    default:
      break;
  }
}

void HelloWorldPeripheral::didReceiveError(uint8_t pipe, uint8_t errorCode) {
  INFO_LOG(F("didReceiveError on pipe:"));
  INFO_LOG(pipe, HEX);
  INFO_LOG(errorCode, HEX);
}

void HelloWorldPeripheral::didStartAdvertising() {
  readParams();
}

void HelloWorldPeripheral::didConnect() {
  uint16_t bigVal = int16HostToBig(updatePeriod);
  setData(PIPE_HELLO_WORLD_UPDATE_PERIOD_SET, (uint8_t*)&bigVal, 2);
}

bool HelloWorldPeripheral::doTimingChange() {
  return isPipeAvailable(PIPE_HELLO_WORLD_GREETING_TX) || isPipeAvailable(PIPE_BATTERY_BATTERY_LEVEL_TX);
}

void HelloWorldPeripheral::loop() {
  if (millis() % updatePeriod == 0) {
    setGreeting();
    getBatteryLevel();
    getTemperature();
    getBLEAddress();
  }
  BlueCapPeripheral::loop();
}

void HelloWorldPeripheral::begin() {
  BlueCapPeripheral::begin();
}

void HelloWorldPeripheral::setUpdatePeriod(uint8_t* data, uint8_t size) {
    uint16_t bigVal, hostVal;
    memcpy(&bigVal, data, PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK_MAX_SIZE);
    hostVal = int16BigToHost(bigVal);
    if (hostVal > MIN_UPDATE_PERIOD && hostVal < MAX_UPDATE_PERIOD) {
      updatePeriod = hostVal;
      if (sendAck(PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK)) {
        writeParams();
      }
    } else {
      sendNack(PIPE_HELLO_WORLD_UPDATE_PERIOD_RX_ACK, INVALID_UPDATE_PERIOD_ERROR);
      INFO_LOG(F("INVALID_UPDATE_PERIOD_ERROR"));
    }
    INFO_LOG(F("Hello World Update Period Update"));
    INFO_LOG(updatePeriod, DEC);
}

void HelloWorldPeripheral::setGreeting() {
  char* greeting = greetings[greetingIndex];
  INFO_LOG(F("Greeting"));
  INFO_LOG(greeting);
  sendData(PIPE_HELLO_WORLD_GREETING_TX, (uint8_t*)greeting, strlen(greeting) + 1);
  setData(PIPE_HELLO_WORLD_GREETING_SET, (uint8_t*)greeting, strlen(greeting) + 1);
  greetingIndex++;
  if (greetingIndex >= GREETING_COUNT) {
    greetingIndex = 0;
  }
}

void HelloWorldPeripheral::setBatteryLevel(uint8_t* data, uint8_t size) {
  uint16_t deviceVal;
  memcpy(&deviceVal, data, 2);
  float level = 3.52 * (float)int16BigToHost(deviceVal);
  if (deviceBatteryLevelInitial < 0.0) {
    deviceBatteryLevelInitial = level;
  }
  uint8_t percentage = (uint8_t)(100.0*level/deviceBatteryLevelInitial);
  INFO_LOG(F("setBatteryLevel level, percentage:"));
  INFO_LOG(level);
  INFO_LOG(percentage);
  sendData(PIPE_BATTERY_BATTERY_LEVEL_TX, &percentage, 1);
  setData(PIPE_BATTERY_BATTERY_LEVEL_SET, &percentage, 1);
}

void HelloWorldPeripheral::setTemperature(uint8_t* data, uint8_t size) {
  int16_t deviceVal;
  memcpy(&deviceVal, data, 2);
  int16_t temp = int16BigToHost(deviceVal) / 4;
  INFO_LOG(F("setTemperature temp:"));
  INFO_LOG(temp, DEC);
  sendData(PIPE_TEMPERATURE_TEMPERATURE_TX, data, 2);
  setData(PIPE_TEMPERATURE_TEMPERATURE_SET, data, 2);
}

void HelloWorldPeripheral::setBLEAddress(uint8_t* data, uint8_t size) {
  INFO_LOG(F("setBLEAddress"));
  INFO_LOG(F("size, values:"));
  INFO_LOG(size);
  for(int i=0; i < size; i++) {
    INFO_LOG(data[i], HEX);
  }
  setData(PIPE_BLE_DEVICE_ADDRESS_BLE_ADDRESS_SET, &data[1], PIPE_BLE_DEVICE_ADDRESS_BLE_ADDRESS_SET_MAX_SIZE);
  setData(PIPE_BLE_DEVICE_ADDRESS_BLE_ADDRESS_TYPE_SET, data, PIPE_BLE_DEVICE_ADDRESS_BLE_ADDRESS_TYPE_SET_MAX_SIZE);
}

void HelloWorldPeripheral::writeParams() {
  INFO_LOG(F("writeParams"));
  eeprom_write_word(&statusAddress, 1);
  eeprom_write_word(&updatePeriodAddress, updatePeriod);
}

void HelloWorldPeripheral::readParams() {
  uint16_t status = eeprom_read_word(&statusAddress);
  INFO_LOG(F("readParams status:"));
  INFO_LOG(status, DEC);
  if (status == 1) {
    updatePeriod = eeprom_read_word(&updatePeriodAddress);
    INFO_LOG(F("readParams EEPROM updatePeriod:"));
  } else {
    INFO_LOG(F("readParams initialize updatePeriod:"));
    updatePeriod = INITIAL_UPDATE_PERIOD;
    writeParams();
  }
  INFO_LOG(updatePeriod, DEC);
}
