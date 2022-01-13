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


// Broeadcast address to all peers
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