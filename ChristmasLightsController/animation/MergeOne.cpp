#include "MergeOne.h"

#include "manipulation/ColorManipulation.h"

MergeOne::MergeOne(AbstractLedStrip* strip) :
    Animation(0x010b, strip, 8, 30),
    cl(0),
    cr(0),
    l(0),
    r(0)
{
}

void MergeOne::Init()
{
    l = 0;
    r = _strip->numPixels();
    byte indx = random(256);
    cl = ColorFromColorWheel(indx);
    indx += random(4, 16);
    cr = ColorFromColorWheel(indx);
    _strip->clear();
}

void MergeOne::Show()
{
    if (l < r) {
        _strip->setPixelColor(l, cl);
        _strip->setPixelColor(r, cr);
    } else {
        uint32_t c = _strip->getPixelColor(l);
        c = ColorSuperPosition(c, cl);
        _strip->setPixelColor(l, c);
        c = _strip->getPixelColor(r);
        c = ColorSuperPosition(c, cr);
        _strip->setPixelColor(r, c);
    }

    --r;
    ++l;
    if (r < 0) { // Force the strip clerance
        _needsClearance = true;
        _complete = true;
        return;
    }
    _complete = false;
}