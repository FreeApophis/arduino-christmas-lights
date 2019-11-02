#include "CollideOne.h"

#include "ColorManipulation.h"

CollideOne::CollideOne(AbstractLedStrip* strip) :
    Animation(strip, 2, 1, 3),
    cl(0),
    cr(0),
    l(0),
    r(0),
    boom(false)
{
}

void CollideOne::Init()
{
    l = 0;
    r = _strip->numPixels() - 1;
    byte w = random(256);
    cl = ColorFromColorWheel(w);
    w += random(8, 16);
    cr = ColorFromColorWheel(w);
    _strip->clear();
    boom = false;
}

void CollideOne::Show()
{
    if (boom) {
        _strip->setPixelColor(l, 0xffffff);
        _strip->setPixelColor(r, 0xffffff);
        if ((r - l) >= 12) {
            _strip->setPixelColor(l + 6, 0);
            _strip->setPixelColor(r - 6, 0);
        }
        --l;
        ++r;
        if (l < 0) {
            Init();
            _complete = true;
            return;
        }
    } else {
        if (l < r) {
            _strip->setPixelColor(l, cl);
            _strip->setPixelColor(r, cr);
            --r;
            ++l;
        } else {
            boom = true;
        }
    }
    _complete = false;
}