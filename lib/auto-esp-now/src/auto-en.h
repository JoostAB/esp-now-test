/**
 * @file auto-en.h
 * @author Joost Bloemsma (joost.a@bloemsma.net)
 * @brief 
 * @version 1.0
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# pragma once
#ifndef _AUTO_EN_H_
#define _AUTO_EN_H_

#include <Arduino.h>
#include <debug.h>
#include "aen-messages.h"

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

#ifndef AUTOEN_ID
/**
 * @brief Unique identifier for your network
 * 
 * Regenerate this UUID if you plan to start creating 
 * devices for a new network, and make sure it is included in 
 * the code for all devices (both controller and nodes) that 
 * are to be used on the same network.
 * 
 * There is actually no need to create an official UUID, just
 * a random sequence of 16 bytes will also work, as long it is known
 * to all nodes on the same network.
 * 
 * A good link to generate the UUID is 
 * https://excusemeplease.org/computers/uuid/converter/.
 * There you can also convert it into a byte array.
 */
#define AUTOEN_ID { 0xc9, 0x9a, 0xdd, 0x13, 0x91, 0xd3, 0x4e, 0xb6, 0x9a, 0x60, 0x46, 0x6a, 0x55, 0x75, 0x02, 0xb9 }
#endif

const uint8_t networkUuid[16] = AUTOEN_ID;

// Broadcast address to all peers
const uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

bool sendAenMessage(AenMessage* msg) {
  return true;
}
#endif // _AUTO_EN_H_
