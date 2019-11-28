#pragma once

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <cstdint>
#include <windows.h>

using byte = unsigned char;

#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

int random(int maxVal);
int random(int minVal, int maxVal);

void incrementMillis(long millis);
unsigned long millis();
void delay(unsigned long);



template<class T>
void swap(T& a, T& b) noexcept
{
    T c(a);
    a = b;
    b = c;
}
