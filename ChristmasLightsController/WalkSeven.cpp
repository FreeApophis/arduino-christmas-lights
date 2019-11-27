#include "WalkSeven.h"
#include "Helper.h"

WalkSeven::WalkSeven(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 9, 8, 15)
{
}

void WalkSeven::Init()
{
    w = random(256);
    fwd = random(2);
    ch_dir = random(30, 100);
    period = random(13, 20);
    curs = 0;
}

void WalkSeven::Show()
{
    BrightnessManipulation::changeAll(-64);

    int n = _strip->numPixels();
    uint32_t c1 = ColorFromColorWheel(w);
    w += 71;
    for (int i = curs; i < n; i += period) {
        uint32_t c2 = _strip->getPixelColor(i);
        c2 = ColorSuperPosition(c1, c2);
        _strip->setPixelColor(i, c2);
    }

    if (fwd)
        ++curs;
    else
        --curs;
    curs %= period;

    if (--ch_dir < 0) {
        ch_dir = random(70, 300);
        fwd = !fwd;
    }
}