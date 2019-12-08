#pragma once

#include <cstdint>

class AbstractLedStrip {
  public:
    virtual uint16_t numPixels() const = 0;
    virtual uint32_t getPixelColor(uint16_t n) const = 0;
    virtual void setPixelColor(uint16_t n, uint32_t c) = 0;
    //virtual void clear() = 0;
    virtual void show() = 0;
    virtual void begin() = 0;
    virtual void setBrightness(uint8_t brightness) = 0;

  protected:
    ~AbstractLedStrip() = default;
};
