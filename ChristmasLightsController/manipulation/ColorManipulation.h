#pragma once
#include "framework.h"

#include <cstdint>

auto ToColor(uint8_t r, uint8_t g, uint8_t b) -> uint32_t;

auto ExtractRed(const uint32_t color) -> uint8_t;
auto ExtractGreen(const uint32_t color) -> uint8_t;
auto ExtractBlue(const uint32_t color) -> uint8_t;

auto AddColors(uint32_t color1, uint32_t color2) -> uint32_t;
auto SubtractColors(uint32_t minuend, uint32_t subtrahend) -> uint32_t;
auto ColorSuperPosition(uint32_t color1, uint32_t color2) -> uint32_t;

auto ColorFromColorWheel(byte positionOnWheel) -> uint32_t;
auto Shimmer(uint32_t color) -> uint32_t;
