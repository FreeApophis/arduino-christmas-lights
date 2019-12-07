#include "Brighten.h"

#include "manipulation/ColorManipulation.h"

Brighten::Brighten(AbstractLedStrip* strip) :
    Clearance(strip),
    _step(0)
{
}

auto Brighten::Init() -> void
{
    _complete = false;
    _step = 0;
}

auto ToWhite(const int32_t color) -> int32_t
{
    const auto red = (ExtractRed(color) + 255 * 2) / 3;
    const auto green = (ExtractGreen(color) + 255 * 2) / 3;
    const auto blue = (ExtractBlue(color) + 255 * 2) / 3;

    return ToColor(red, green, blue);
}

auto Brighten::Show() -> void
{
    if (_step < 6) {
        for (auto index = 0; index < _strip->numPixels(); ++index) {
            const auto color = _strip->getPixelColor(index);
            _strip->setPixelColor(index, ToWhite(color));
        }
    } else {
        _complete = FadeAll(40);
    }

    ++_step;
}
