#pragma once

#include <cstdint>

extern "C" __declspec(dllexport) uint16_t setup();
extern "C" __declspec(dllexport) uint32_t* loop(long millis);
extern "C" __declspec(dllexport) void setAnimation(unsigned short animationId);
extern "C" __declspec(dllexport) unsigned short currentAnimationId();