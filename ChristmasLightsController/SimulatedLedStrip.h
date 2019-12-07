#pragma once
#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

#include <cstdint>
#include <vector>

class SimulatedLedStrip final : public AbstractLedStrip {
  public:
    explicit SimulatedLedStrip(byte stripSize);

    auto numPixels() const -> uint16_t override;
    auto getPixelColor(uint16_t n) const -> uint32_t override;
    auto setPixelColor(uint16_t n, uint32_t c) -> void override;
    auto show() -> void override;
    auto begin() -> void override;
    auto setBrightness(uint8_t brightness) -> void override;

    auto CurrentPixels() -> std::vector<uint32_t>&;

  private:
    std::vector<uint32_t> _pixels;
};
