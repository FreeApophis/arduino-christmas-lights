#pragma once
#include "framework.h"

#include <cstdint>

uint32_t ToColor(uint8_t r, uint8_t g, uint8_t b);

uint32_t AddColors(uint32_t color1, uint32_t color2);
uint32_t SubtractColors(uint32_t minuend, uint32_t subtrahend);
uint32_t ColorSuperPosition(uint32_t color1, uint32_t color2);

uint32_t ColorFromColorWheel(byte positionOnWheel);
uint32_t Shimmer(uint32_t color);
