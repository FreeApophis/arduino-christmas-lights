#pragma once

#include "AbstractLedStrip.h"

#include "framework.h"

#include <cstdint>
#include <vector>

class SimulatedLedStrip : public AbstractLedStrip {
  public:
    SimulatedLedStrip(byte stripSize);

    uint16_t numPixels() const override;
    uint32_t getPixelColor(uint16_t n) const override;
    void setPixelColor(uint16_t n, uint32_t c) override;
    void clear() override;
    void show() override;
    void begin() override;
    void setBrightness(uint8_t brightness) override;

    ~SimulatedLedStrip() = default;

    std::vector<uint32_t>& CurrentPixels();

  private:
    std::vector<uint32_t> _pixels;
};
