#include "Toward.h"

#include "manipulation/ColorManipulation.h"

Toward::Toward(AbstractLedStrip* strip) :
    Animation(0x011c, strip, 5, 10)
{
}

void Toward::Show()
{
    const int n = _strip->numPixels();
    for (int i = n - 2; i >= 2; i -= 2) {
        const uint32_t c = _strip->getPixelColor(i - 2);
        _strip->setPixelColor(i, c);
    }
    for (int i = 1; i < n - 1; i += 2) {
        const uint32_t c = _strip->getPixelColor(i + 2);
        _strip->setPixelColor(i, c);
    }
    if (random(16) == 0) {
        _strip->setPixelColor(0, 0);
        _strip->setPixelColor(n - 1, 0);
        w += 4;
    } else {
        _strip->setPixelColor(0, ColorFromColorWheel(w + 128));
        _strip->setPixelColor(n - 1, ColorFromColorWheel(w));
    }
}
