#include "Toward.h"

#include "manipulation/ColorManipulation.h"

Toward::Toward(AbstractLedStrip* strip) :
    Animation(0x011c, strip, 5, 10),
    _wheelIndex(0)
{
}

auto Toward::Init() -> void
{
    _wheelIndex = random(256);
}

auto Toward::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    for (int index = pixelCount - 2; index >= 2; index -= 2) {
        const uint32_t c = _strip->getPixelColor(index - 2);
        _strip->setPixelColor(index, c);
    }
    for (auto index = 1; index < pixelCount - 1; index += 2) {
        const uint32_t c = _strip->getPixelColor(index + 2);
        _strip->setPixelColor(index, c);
    }
    if (random(16) == 0) {
        _strip->setPixelColor(0, 0);
        _strip->setPixelColor(pixelCount - 1, 0);
        _wheelIndex += 4;
    } else {
        _strip->setPixelColor(0, ColorFromColorWheel(_wheelIndex + 128));
        _strip->setPixelColor(pixelCount - 1, ColorFromColorWheel(_wheelIndex));
    }
}
