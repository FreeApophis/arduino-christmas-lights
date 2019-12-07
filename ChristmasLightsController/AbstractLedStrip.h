#pragma once

#include <cstdint>

class AbstractLedStrip {
  public:
    AbstractLedStrip() = default;
    virtual ~AbstractLedStrip() = default;

    AbstractLedStrip(const AbstractLedStrip& animation) = delete;
    AbstractLedStrip(AbstractLedStrip&& animation) = delete;
    auto operator=(const AbstractLedStrip& animation) -> void = delete;
    auto operator=(AbstractLedStrip&& animation) -> void = delete;

    virtual auto numPixels() const -> uint16_t = 0;
    virtual auto getPixelColor(uint16_t n) const -> uint32_t = 0;
    virtual auto setPixelColor(uint16_t n, uint32_t c) -> void = 0;
    //virtual auto clear() -> void = 0;
    virtual auto show() -> void = 0;
    virtual auto begin() -> void = 0;
    virtual auto setBrightness(uint8_t brightness) -> void = 0;
};
