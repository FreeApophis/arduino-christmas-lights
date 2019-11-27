#pragma once

#include "framework.h"

uint32_t ToColor(uint8_t r, uint8_t g, uint8_t b);

uint32_t ColorFromColorWheel(byte WheelPos);

uint32_t ColorSuperPosition(uint32_t color1, uint32_t color2);

