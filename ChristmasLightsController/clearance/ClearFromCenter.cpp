#include "ClearFromCenter.h"

#include "../Helper.h"

ClearFromCenter::ClearFromCenter(AbstractLedStrip* strip):
    Clearance(strip)
{
}

void ClearFromCenter::init()
{
    complete = false;
    color = ColorFromColorWheel(random(256));
    l = _strip->numPixels() / 2;
    r = l + 1;
}

void ClearFromCenter::show()
{
    if (r < int(_strip->numPixels())) {
        _strip->setPixelColor(r, color);
        if (r > 0)
            _strip->setPixelColor(r - 1, 0);
    }
    ++r;
    if (l >= 0) {
        _strip->setPixelColor(l, color);
        if (l < int(_strip->numPixels() - 1))
            _strip->setPixelColor(l + 1, 0);
    }
    --l;
    complete = (l < 0);
}
