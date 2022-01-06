/**
 * @file debug.h
 * @author Joost Bloemsma (joost.a@bloemsma.net)
 * @brief Some macros to enabled debuglogging.
 * @version 1.0
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * By passing the DEBUGLOG=1 buildflag, these macro's are enabled and will log to std Serial.
 * It will also start the default serial output, using the baudrate set with SERIALBAUDRATE, either 
 * defined or passed as buildflag.
 * If no DEBUGLOG is set, or set to 0, then all these macro's end up in nothing.
 */
# pragma once
#ifndef _JB_DEBUG_H
#define _JB_DEBUG_H

#include <Arduino.h>

// Debugging switches and macros
// #ifndef DEBUGLOG
// # define DEBUGLOG 0 // Switch debug output on and off by 1 or 0
// #endif

#if DEBUGLOG
#define PRINTS(s)                    { Serial.print(F(s)); }
#define PRINT(s,v)                   { Serial.print(F(s)); Serial.print(v); }
#define PRINTF(s,v1)                 { Serial.printf(s, v1); }
#define PRINTF2(s,v1,v2)             { Serial.printf(s, v1, v2); }
#define PRINTF3(s,v1,v2,v3)          { Serial.printf(s, v1, v2, v3); }
#define PRINTF4(s,v1,v2,v3,v4)       { Serial.printf(s, v1, v2, v3, v4); }
#define PRINTF5(s,v1,v2,v3,v4,v5)    { Serial.printf(s, v1, v2, v3, v4, v5); }
#define PRINTF6(s,v1,v2,v3,v4,v5,v6) { Serial.printf(s, v1, v2, v3, v4, v5, v6); }
#define PRINTLNS(s)                  { Serial.println(F(s)); }
#define PRINTLN(s,v)                 { Serial.print(F(s)); Serial.println(v); }
#define PRINTLF                      Serial.println()
// #if SERIALBAUDRATE
//   Serial.begin(SERIALBAUDRATE);
// #else
//   Serial.begin(115200);
// #endif

#else
// No debugging, replace all PRINT*** calls with nothing
#define PRINTS(s)
#define PRINT(s,v)
#define PRINTX(s,v)
#define PRINTF(s,v1)
#define PRINTF2(s,v1,v2)
#define PRINTF3(s,v1,v2,v3)
#define PRINTF4(s,v1,v2,v3,v4)
#define PRINTF5(s,v1,v2,v3,v4,v5)
#define PRINTF6(s,v1,v2,v3,v4,v5,v6)
#define PRINTLNS(s)
#define PRINTLN(s,v)
#define PRINTLNX(s,v)
#define PRINTLF
#endif

#endif // _JB_DEBUG_H
