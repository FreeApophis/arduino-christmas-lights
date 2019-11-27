#include "CollEnd.h"
#include "Helper.h"


CollEnd::CollEnd(AbstractLedStrip* strip, byte duration):
    BlendManipulations(strip),
    Animation(strip, 10, 1, 6),
    cl(0),
    cr(0),
    l(0),
    r(0),
    ml(0),
    mr(0)
{
}

void CollEnd::Init()
{
    ml = _strip->numPixels() - 1;
    mr = 0;
    newColors();
}

void CollEnd::Show()
{
    // blend colors in the both ends
    if (mr > 1) {
        for (int i = 0; i < mr; ++i)
            BlendManipulations::blendPixel(i);
        for (uint16_t i = ml; i < _strip->numPixels(); ++i)
            BlendManipulations::blendPixel(i);
    }

    // New colors are moving to the other end
    if (l <= ml) {
        if (l > (mr + 1))
            _strip->setPixelColor(l - 2, 0);
        _strip->setPixelColor(l, cl);
    }
    if (r >= mr) {
        if (r < (ml - 1))
            _strip->setPixelColor(r + 2, 0);
        _strip->setPixelColor(r, cr);
    }
    if ((l >= ml) && (r <= mr)) {
        ml--;
        mr++;
        if (ml < 0) {
            _needsClear = true; // Force the strip clerance
            _complete = true;
            return;
        }
        newColors();
        return;
    }
    l++;
    r--;
    _complete = false;
}

void CollEnd::newColors()
{
    cl = ColorFromColorWheel(random(256));
    cr = ColorFromColorWheel(random(256));
    l = mr;
    r = ml;
}
