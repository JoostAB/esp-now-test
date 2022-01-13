/**
 * @file baseincludes.h
 * @author Joost Bloemsma (joost.a@bloemsma.net)
 * @brief 
 * @version 1.0
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
# pragma once
#ifndef _JB_BASEINCLUDES_H
#define _JB_BASEINCLUDES_H

#include <Arduino.h>
#include <debug.h>

#ifdef M5STACK_FIRE
// Uncomment next line if Accelerometer/Gyroscope is to be used
// #define M5STACK_MPU6886 1 
#include <M5Stack.h>
#endif

#define XQUOTE(x) #x
#define QUOTE(x) XQUOTE(x)


#endif // _JB_BASEINCLUDES_H
