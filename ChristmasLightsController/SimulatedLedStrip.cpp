#include "SimulatedLedStrip.h"

#include <cstdint>

SimulatedLedStrip::SimulatedLedStrip(byte stripSize)
{
    _pixels.resize(stripSize, 0);
}

uint16_t SimulatedLedStrip::numPixels() const
{
    return static_cast<uint16_t>(_pixels.size());
}

inline uint32_t SimulatedLedStrip::getPixelColor(uint16_t n) const
{
    if (n < _pixels.size()) {
        return _pixels[n];
    }
}

void SimulatedLedStrip::setPixelColor(uint16_t n, uint32_t c)
{
    if (n < _pixels.size()) {
        _pixels[n] = c;
    }
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

std::vector<uint32_t>& SimulatedLedStrip::CurrentPixels()
{
    return _pixels;
}
