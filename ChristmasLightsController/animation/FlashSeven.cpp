#include "FlashSeven.h"
#include "../Helper.h"

FlashSeven::FlashSeven(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 9, 4, 8),
    curs(0),
    w(0),
    fwd(false),
    ch_dir(0),
    period(0)
{
}

void FlashSeven::Init()
{
    w = random(256);
    fwd = random(2);
    ch_dir = random(30, 100);
    period = random(7, 20);
    curs = 0;
}

void FlashSeven::Show()
{
    BrightnessManipulation::changeAll(-64);

    const int n = _strip->numPixels();
    for (int i = curs; i < n; i += period) {
        BrightnessManipulation::change(i, -128);
    }

    if (fwd)
        ++curs;
    else
        --curs;
    curs %= period;

    const uint32_t c = ColorFromColorWheel(w);
    w += 71;
    for (int i = curs; i < n; i += period) {
        _strip->setPixelColor(i, c);
    }

    if (--ch_dir < 0) {
        ch_dir = random(70, 300);
        fwd = !fwd;
    }
}