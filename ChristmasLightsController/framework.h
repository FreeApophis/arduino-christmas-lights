#pragma once

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <cstdint>
#include <windows.h>

using byte = unsigned char;

#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

auto random(int maxVal) -> int;
auto random(int minVal, int maxVal) -> int;

auto incrementMillis(long millis) -> void;
auto millis() -> unsigned long;
auto delay(unsigned long) -> void;

template<class T>
auto swap(T& a, T& b) noexcept -> void
{
    T c(a);
    a = b;
    b = c;
}
