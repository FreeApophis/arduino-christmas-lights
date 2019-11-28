#include "EvenOdd.h"

#include "ColorManipulation.h"

EvenOdd::EvenOdd(AbstractLedStrip* strip, byte duration) :
    Animation(0x0106, strip, duration, 10, 20),
    cl(0),
    cr(0),
    l(0),
    r(0)
{
}

void EvenOdd::Init()
{
    byte indx = random(256);
    cl = ColorFromColorWheel(indx);
    indx += random(4, 16);
    cr = ColorFromColorWheel(indx);
    l = 0;
    r = _strip->numPixels() - 1; // r is Odd
}

void EvenOdd::Show()
{
    _strip->setPixelColor(l, cl);
    _strip->setPixelColor(r, cr);
    l += 2;
    r -= 2;
    if (r < 0) {
        if (cr) {
            cr = cl = 0;
            l = 0;
            r = _strip->numPixels() - 1; // r is Odd
        } else {
            Init();
            _complete = true;
            return;
        }
    }
    _complete = false;
}