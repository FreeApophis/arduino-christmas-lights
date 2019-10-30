#include "TowardRain.h"
#include "../Helper.h"

TowardRain::TowardRain(AbstractLedStrip* strip, byte duration):
    Animation(strip, 8, 10, 20)
{
}

void TowardRain::Init()
{
    w = random(256);
}

void TowardRain::Show()
{
    int n = _strip->numPixels();
    for (int i = n - 2; i >= 2; i -= 2) {
        uint32_t c = _strip->getPixelColor(i - 2);
        _strip->setPixelColor(i, c);
    }
    for (int i = 1; i < n - 1; i += 2) {
        uint32_t c = _strip->getPixelColor(i + 2);
        _strip->setPixelColor(i, c);
    }

    if (!random(17)) {
        _strip->setPixelColor(0, 0);
        _strip->setPixelColor(n - 1, 0);
    } else {
        _strip->setPixelColor(0, ColorFromColorWheel(w));
        w += 9;
        _strip->setPixelColor(n - 1, ColorFromColorWheel(w));
        w += 3;
    }
}
