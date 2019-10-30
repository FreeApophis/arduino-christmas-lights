#include "MergeOne.h"
#include "../Helper.h"

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
        _needsClear = true;
        _complete = true;
        return;
    }
    _complete = false;
}