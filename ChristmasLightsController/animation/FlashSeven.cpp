#include "FlashSeven.h"
#include "../Helper.h"

FlashSeven::FlashSeven(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 9, 4, 8)
{
}

void FlashSeven::init()
{
    w = random(256);
    fwd = random(2);
    ch_dir = random(30, 100);
    period = random(7, 20);
    curs = 0;
}

void FlashSeven::show()
{
    BrightnessManipulation::changeAll(-64);

    int n = _strip->numPixels();
    for (int i = curs; i < n; i += period) {
        BrightnessManipulation::change(i, -128);
    }

    if (fwd)
        ++curs;
    else
        --curs;
    curs %= period;

    uint32_t c = ColorFromColorWheel(w);
    w += 71;
    for (int i = curs; i < n; i += period) {
        _strip->setPixelColor(i, c);
    }

    if (--ch_dir < 0) {
        ch_dir = random(70, 300);
        fwd = !fwd;
    }
}