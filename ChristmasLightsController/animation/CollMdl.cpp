#include "CollMdl.h"

#include "ColorManipulation.h"

CollMdl::CollMdl(AbstractLedStrip* strip, byte duration):
    Animation(strip, 8, 1, 6),
    cl(0),
    cr(0),
    l(0),
    r(0),
    ml(0),
    mr(0),
    clr(false)
{
}

void CollMdl::Init()
{
    ml = (_strip->numPixels() - 1) / 2;
    mr = ml + 1;
    newColors();
    clr = false;
}

void CollMdl::Show()
{
    if (clr) {
        _strip->setPixelColor(l, 0);
        _strip->setPixelColor(r, 0);
        l--;
        r++;
        if (l < 0) {
            Init();
            _complete = true;
        }
        return;
    }

    // blend colors in the middle
    if ((mr - ml) > 1) {
        for (int i = ml; i < mr; ++i) {
            _strip->setPixelColor(i, Shimmer(_strip->getPixelColor(i)));

        }
    }

    // New colors are moving to the center
    if (l <= ml) {
        if (l > 1)
            _strip->setPixelColor(l - 2, 0);
        _strip->setPixelColor(l, cl);
    }
    if (r >= mr) {
        if (r < int(_strip->numPixels() - 2))
            _strip->setPixelColor(r + 2, 0);
        _strip->setPixelColor(r, cr);
    }
    if ((l >= ml) && (r <= mr)) {
        ml--;
        mr++;
        if (ml < 0) {
            clr = true;
            l = (_strip->numPixels() - 1) / 2;
            r = l + 1;
            return;
        }
        newColors();
        return;
    }
    l++;
    r--;
    _complete = false;
}

void CollMdl::newColors()
{
    cl = ColorFromColorWheel(random(256));
    cr = ColorFromColorWheel(random(256));
    l = 0;
    r = _strip->numPixels() - 1;
}