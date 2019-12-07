#include "Brighten.h"

#include "manipulation/ColorManipulation.h"

Brighten::Brighten(AbstractLedStrip* strip) :
    Clearance(strip),
    _step(0)
{
}

void Brighten::Init()
{
    _complete = false;
    _step = 0;
}

int32_t ToWhite(int32_t color)
{
    const auto red = (ExtractRed(color) + 255 * 2) / 3;
    const auto green = (ExtractGreen(color) + 255 * 2) / 3;
    const auto blue = (ExtractBlue(color) + 255 * 2) / 3;

    return ToColor(red, green, blue);
}

void Brighten::Show()
{
    if (_step < 6) {
        for (auto index = 0; index < _strip->numPixels(); ++index) {
            const auto color = _strip->getPixelColor(index);
            _strip->setPixelColor(index, ToWhite(color));
        }
    } else {
        _complete = Clearance::FadeAll(40);
    }

    ++_step;
}
