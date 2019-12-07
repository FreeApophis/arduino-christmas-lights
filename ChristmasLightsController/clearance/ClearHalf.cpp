#include "ClearHalf.h"

ClearHalf::ClearHalf(AbstractLedStrip* strip) :
    Clearance(strip),
    _oneStep(0)
{
}

auto ClearHalf::Init() -> void
{
    _complete = false;
    _oneStep = _strip->numPixels() / 2;
}

auto ClearHalf::Show() -> void
{
    for (uint16_t index = 0; index < _strip->numPixels(); index += _oneStep) {
        if (index > 0 || (_oneStep == 1)) {
            _strip->setPixelColor(index, 0);
        }
    }

    _complete = ((_oneStep >>= 1) == 0);
}
