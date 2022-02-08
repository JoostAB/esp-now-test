/**
 * @file main.h
 * @author Joost Bloemsma (joost.a@bloemsma.net)
 * @brief 
 * @version 1.0
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <baseincludes.h>
#include <espnow_generic.h>
#include <display.h>
#include "..\lib\auto-esp-now\src\auto-en.h"

#define NETWORK_UUID c99add13-91d3-4eb6-9a60-466a557502b9

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
const uint8_t networkUuid[16] = 
  { 0xc9, 0x9a, 0xdd, 0x13, 
    0x91, 0xd3, 0x4e, 0xb6, 
    0x9a, 0x60, 0x46, 0x6a, 
    0x55, 0x75, 0x02, 0xb9 };

// Broadcast address to all peers
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Address of peer
//uint8_t peerAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// Heltec 8
uint8_t peerAddress[] = {0x84, 0x0D, 0x8E, 0xAB, 0xB9, 0x37};

// DevKit 32
// uint8_t peerAddress[] = {0x24, 0x0A, 0xC4, 0x97, 0x53, 0xA8};

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  char a[32];
  int b;
  float c;
  bool d;
} struct_message;