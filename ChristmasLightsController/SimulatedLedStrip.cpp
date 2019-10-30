#include "SimulatedLedStrip.h"

#include <cstdint>


SimulatedLedStrip::SimulatedLedStrip(byte stripSize)
{
    _pixels.resize(stripSize);
}

uint16_t SimulatedLedStrip::numPixels() const
{
    return static_cast<uint16_t>(_pixels.size());
}

inline uint32_t SimulatedLedStrip::getPixelColor(uint16_t n) const
{
    return _pixels[n];
}

void SimulatedLedStrip::setPixelColor(uint16_t n, uint32_t c)
{
    _pixels[n] = c;
}

void SimulatedLedStrip::clear()
{
    for (auto& pixel : _pixels) {
        pixel = 0;
    }
}

void SimulatedLedStrip::show()
{
    // Well here we are...
}

void SimulatedLedStrip::begin()
{
}

void SimulatedLedStrip::setBrightness(uint8_t brightness)
{
    // we don't care for brightness in the simulator...
}
