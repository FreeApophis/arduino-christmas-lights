#include "SimulatedLedStrip.h"

#include <cstdint>

SimulatedLedStrip::SimulatedLedStrip(byte stripSize)
{
    _pixels.resize(stripSize, 0);
}

auto SimulatedLedStrip::numPixels() const -> uint16_t
{
    return static_cast<uint16_t>(_pixels.size());
}

auto SimulatedLedStrip::getPixelColor(uint16_t n) const -> uint32_t
{
    return n < _pixels.size()
               ? _pixels[n]
               : 0;
}

auto SimulatedLedStrip::setPixelColor(uint16_t n, uint32_t c) -> void
{
    if (n < _pixels.size()) {
        _pixels[n] = c;
    }
}

auto SimulatedLedStrip::show() -> void
{
    // Well here we are...
}

auto SimulatedLedStrip::begin() -> void
{
}

auto SimulatedLedStrip::setBrightness(uint8_t) -> void
{
    // we don't care for brightness in the simulator...
}

auto SimulatedLedStrip::CurrentPixels() -> std::vector<uint32_t>&
{
    return _pixels;
}
