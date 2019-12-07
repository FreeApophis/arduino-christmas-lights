#include "TowardRain.h"

#include "manipulation/ColorManipulation.h"

TowardRain::TowardRain(AbstractLedStrip* strip) :
    Animation(0x011d, strip, 10, 20),
    _wheelIndex(0)
{
}

auto TowardRain::Init() -> void
{
    _wheelIndex = random(256);
}

auto TowardRain::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    for (auto index = pixelCount - 2; index >= 2; index -= 2) {
        const auto color = _strip->getPixelColor(index - 2);
        _strip->setPixelColor(index, color);
    }
    for (int index = 1; index < pixelCount - 1; index += 2) {
        const auto color = _strip->getPixelColor(index + 2);
        _strip->setPixelColor(index, color);
    }

    if (!random(17)) {
        _strip->setPixelColor(0, 0);
        _strip->setPixelColor(pixelCount - 1, 0);
    } else {
        _strip->setPixelColor(0, ColorFromColorWheel(_wheelIndex));
        _wheelIndex += 9;
        _strip->setPixelColor(pixelCount - 1, ColorFromColorWheel(_wheelIndex));
        _wheelIndex += 3;
    }
}
