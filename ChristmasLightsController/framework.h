#pragma once

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <cstdlib>
#include <cstdint>

using byte = unsigned char;

#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

int random(int maxVal);
int random(int minVal, int maxVal);

void incrementMillis();
unsigned long millis();
void delay(unsigned long);
#else
#    include <arduino.h>
#endif
