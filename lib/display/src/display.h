/**
 * @file display.h
 * @author Joost Bloemsma (joost.a@bloemsma.net)
 * @brief 
 * @version 1.0
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# pragma once
#ifndef _JB_DISPLAY_H
#define _JB_DISPLAY_H

#ifdef HAS_DISPLAY
#include <baseincludes.h>

#ifdef HELTEC_WIFI_KIT_8
  #define _USE_U8GLIB
#endif

#ifdef _USE_U8GLIB
  //#include <U8g2lib.h>
  #include <U8x8lib.h>
  #define _DISPLAY_RES_X 128
  #define _DISPLAY_RES_Y 32
  //U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 16, /* clock=*/ 5, /* data=*/ 4);   // pin remapping with ESP8266 HW I2C
  U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8( /* reset=*/ 16, /* clock=*/ 5, /* data=*/ 4);
#endif
  
#ifdef M5STACK_FIRE
  #define _DISPLAY_RES_X 320
  #define _DISPLAY_RES_Y 240
#endif

const uint8_t _colCount = _DISPLAY_RES_X / 8;
const uint8_t _rowCount = _DISPLAY_RES_Y / 8;
bool _display_useheader = false;
uint8_t _firstRow = 0;
uint8_t _currentRow = 0;
char * data[_rowCount][_colCount];
char * _header;
bool _displayOn = true;

void display_update() {
#ifdef M5STACK_FIRE
  if (M5.BtnA.wasReleased()) {
    _displayOn = !_displayOn;
    if (_displayOn) {
      //M5.Lcd.wakeup();
      M5.Lcd.writecommand(ILI9341_DISPON);
      M5.Lcd.setBrightness(255);
    } else {
      //M5.Lcd.sleep();
      M5.Lcd.writecommand(ILI9341_DISPOFF);
      M5.Lcd.setBrightness(0);
    }
  }
#endif
}

void display_setup(bool withHeader = false) {
#ifdef _USE_U8GLIB
  _display_useheader = withHeader;
  if (withHeader) {
    _firstRow = 1;
  }
  _currentRow = _firstRow;
  
  u8x8.begin();
  u8x8.clear();
#endif

#ifdef M5STACK_FIRE
  M5.Lcd.setTextSize(2);
#endif

}

void display_header(const char * txt) {
#ifdef _USE_U8GLIB
  if (!_display_useheader) return;
  memcpy(_header, txt, sizeof(&txt));
  u8x8.clearLine(0);
  u8x8.drawString(0,0,txt);
#endif

#ifdef M5STACK_FIRE
  M5.lcd.print(txt);
#endif
}

void display_header(const String txt) {
  display_header(txt.c_str());
}

void display_println(const char * line) {
  Serial.println(line);
}

void display_println(const String line) {
  display_println(line.c_str());
}

#endif // HAS_DISPLAY
#endif // _JB_DISPLAY_H