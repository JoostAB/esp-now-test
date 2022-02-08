/**
 * @file main.cpp
 * @author Joost Bloemsma (joost.a@bloemsma.net)
 * @brief 
 * @version 1.0
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <main.h>

#ifdef ESP8266
  #define TST8266
#elif defined(ESP32)
  #define TST32
#endif

struct_message myData;



#ifdef ESPNOW_CONTROLLER
  #ifdef ESP32
    void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  #elif defined(ESP8266)
    void OnDataSent(uint8_t *mac_addr, uint8_t status) {
  #endif
  PRINTS("Last Packet Send Status: ");
  if (status == ESP_NOW_SEND_SUCCESS) {
    PRINTLN("Delivery ", "success");
  } else {
    PRINTLN("Delivery ", "fail")
  }
  
}
#else
  #ifdef ESP32
    void onDataReceiver(const uint8_t * mac, const uint8_t *incomingData, int len) {
  #elif defined(ESP8266)
    void onDataReceiver(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  #endif
  PRINTLNS("Message received.");
  memcpy(&myData, incomingData, sizeof(myData));
  
  PRINTLN("Bytes received: ", len);
  PRINTLN("Char: ", myData.a);
  PRINTLN("Int: ", myData.b);
  PRINTLN("Float: ", myData.c);
  PRINTLN("Bool: ", myData.d);
  PRINTLF;
}
#endif

void setup() {
  Serial.begin(SERIALBAUDRATE);
  
  #ifdef M5STACK_FIRE
  M5.begin();
  M5.Power.begin();
  #endif
  #ifdef HAS_DISPLAY
    display_setup(true);
  #endif

  WiFi.disconnect();
  #ifdef ESP8266
  ESP.eraseConfig();
  #endif
  WiFi.mode(WIFI_STA);

  // Get Mac Address
  PRINTLN("Mac Address: ", WiFi.macAddress());
  
  #ifdef HAS_DISPLAY
    display_header(WiFi.macAddress());
  #endif

  #ifdef ESPNOW_CONTROLLER
  PRINTLNS("ESP-Now Sender");
  #else
  PRINTLNS("ESP-Now Receiver");
  #endif

  // Initializing the ESP-NOW
  if (esp_now_init() == ESP_OK) {
    PRINTLNS("ESP-NOW initialized");
  } else {
    PRINTLNS("Problem during ESP-NOW init");
    return;
  }

  
  #ifdef ESPNOW_CONTROLLER
    espnow_addpeer(peerAddress, 0);
    espnow_addpeer(broadcastAddress, 0);
    esp_now_register_send_cb(OnDataSent);
  #else
    esp_now_register_recv_cb(onDataReceiver);
  #endif

  AenWelcomeMessage welc;
  sendAenMessage(&welc);
  
}

void loop() {
  #ifdef ESPNOW_CONTROLLER
  static const unsigned long timerDelay = 2000;  // send readings timer
  static unsigned long lastTime = 0;

#ifdef M5STACK_FIRE
  M5.update();
#endif

#ifdef HAS_DISPLAY
  display_update();
#endif

  if ((millis() - lastTime) > timerDelay) {
    strcpy(myData.a, "THIS IS A CHAR");  // Char data
    myData.b = random(1,20);             // Int data
    //myData.c = 1.2;
    myData.c = (random(1000)/100.0);     // Float data
    myData.d = (random(10)>5);           // Boolean data

    // Send message via ESP-NOW
    // PRINTLNS("Sending data...");
    // esp_now_send(peerAddress, (uint8_t *) &myData, sizeof(myData));

    PRINTLNS("Broadacsting data...");
    esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
    

    lastTime = millis();

  }
  #endif
}