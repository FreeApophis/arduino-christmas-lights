#include "EvenOdd.h"
#include "../Helper.h"

void EvenOdd::init()
{
    byte indx = random(256);
    cl = ColorFromColorWheel(indx);
    indx += random(4, 16);
    cr = ColorFromColorWheel(indx);
    l = 0;
    r = _strip->numPixels() - 1; // r is Odd
}

void EvenOdd::show()
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
            init();
            _complete = true;
            return;
        }
    }
    _complete = false;
}