#include "LightHouse.h"

LightHouse::LightHouse(AbstractLedStrip* strip) :
    Animation(0x0109, strip, 6, 2, 10),
    _brightnessManipulation(strip),
    dot{},
    pos(0),
    stp(0),
    incr(0),
    sp(0),
    dlay(0)
{
}

void LightHouse::Init()
{
    uint32_t c = 0xff;
    for (byte i = 0; i <= 4; ++i) {
        dot[i] = c | (c << 8) | (c << 16);
        c >>= 1;
    }
    _brightnessManipulation.setColor(dot[4]);
    pos = random(_strip->numPixels());
    stp = 0;
    sp = random(1, 4);
    dlay = sp;
}

void LightHouse::Show()
{
    _brightnessManipulation.changeAll(-8);
    if (--dlay > 0)
        return;
    dlay = sp;

    int n = _strip->numPixels();
    if (stp <= 0) {
        incr = 1;
        if (pos > n / 2)
            incr = -1;
        stp = random(5, n);
        sp += random(3) - 1;
        if (sp < 1)
            sp = 1;
        else if (sp > 3)
            sp = 3;
    }
    pos += incr;
    pos %= n;

    for (int i = 0; i <= 5; ++i) {
        byte indx = i;
        if (indx >= 1)
            indx--;
        int x = pos + i;
        if (x >= n)
            x -= n;
        else if (x < 0)
            x += n;
        _strip->setPixelColor(x, dot[indx]);
        x = pos - i;
        if (x >= n)
            x -= n;
        else if (x < 0)
            x += n;
        _strip->setPixelColor(x, dot[indx]);
    }
    stp--;
}