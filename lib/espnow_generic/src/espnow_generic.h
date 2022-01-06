/**
 * @file espnow_generic.h
 * @author Joost Bloemsma (joost.a@bloemsma.net)
 * @brief My attempt to make the esp-now api a bit platform independent (esp32/esp8266)
 * @version 1.0
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# pragma once
#ifndef _ESPNOW_GENERIC_H
#define _ESPNOW_GENERIC_H

#include <baseincludes.h>

#ifdef ESP8266
  #include <ESP8266WiFi.h>
  #include <espnow.h>
  
  // Following are defines from esp_now.h for ESP 32
  // Defined here for compatibility
  #define ESP_OK    0   /* Value indicating success (no error) */
  #define ESP_FAIL -1   /* Value indicating failure */
  
  typedef enum {
      ESP_NOW_SEND_SUCCESS = 0,       /* Send ESPNOW data successfully */
      ESP_NOW_SEND_FAIL,              /* Send ESPNOW data fail */
  } esp_now_send_status_t;
#elif defined(ESP32)
  #include <esp_now.h>
  #include <WiFi.h>

  esp_now_peer_info_t peerInfo;
#endif

/**
 * @brief A random key that will be used for encryption
 */
uint8_t _lmk[] = 
  {0x84, 0x0D, 0x8E, 0xAB, 
   0xB9, 0x37, 0x8E, 0xAB,
   0x0A, 0xC4, 0x97, 0x53,
   0xE6, 0x12, 0x00, 0xAB};

//int espnow_addpeer(uint8_t *mac_addr, uint8_t channel, bool encrypt = false, uint8_t *lmk = NULL) {
int espnow_addpeer(uint8_t *mac_addr, uint8_t channel, bool encrypt = false) {
  #ifdef ESP32
      // ESP 32 uses a structure for peer information      
      memcpy(peerInfo.peer_addr, mac_addr, 6);
      peerInfo.channel = channel;
      peerInfo.encrypt = encrypt;
      if (encrypt == true) {
        memcpy(peerInfo.lmk, _lmk, ESP_NOW_KEY_LEN);
      }
      return esp_now_add_peer(&peerInfo);
    #elif defined(ESP8266)
      // ESP 8266 has a simple method with std arguments to add a peer
      if (encrypt) {
        return esp_now_add_peer(mac_addr, ESP_NOW_ROLE_SLAVE, channel, _lmk, 16);
      } else {
        return esp_now_add_peer(mac_addr, ESP_NOW_ROLE_SLAVE, channel, NULL, 0);
      }
    #endif
}

#endif // _ESPNOW_GENERIC_H