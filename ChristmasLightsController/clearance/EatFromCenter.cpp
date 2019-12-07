#include "EatFromCenter.h"

EatFromCenter::EatFromCenter(AbstractLedStrip* strip) :
    Clearance(strip),
    _remaining(0)
{
}

auto EatFromCenter::Init() -> void
{
    _complete = false;
    _remaining = _strip->numPixels() / 2 + 1;
}

auto EatFromCenter::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    const auto halfPixelCount = pixelCount / 2;
    for (auto index = halfPixelCount; index > 0; --index) {
        const auto color = _strip->getPixelColor(index - 1);
        _strip->setPixelColor(index, color);
    }
    for (auto index = halfPixelCount; index < pixelCount - 1; ++index) {
        const uint32_t color = _strip->getPixelColor(index + 1);
        _strip->setPixelColor(index, color);
    }
    _strip->setPixelColor(0, 0);
    _strip->setPixelColor(pixelCount - 1, 0);
    --_remaining;
    _complete = (_remaining <= 0);
}
