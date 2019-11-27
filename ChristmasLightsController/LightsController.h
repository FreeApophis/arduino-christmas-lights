#pragma once

#ifdef _MSC_VER
#include <cstdint>

extern "C" __declspec(dllexport) uint16_t setup();
extern "C" __declspec(dllexport) uint32_t* loop();
#endif