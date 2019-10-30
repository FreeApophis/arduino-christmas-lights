#include "CollMdl.h"

#include "../Helper.h"

CollMdl::CollMdl(AbstractLedStrip* strip, byte duration):
    BlendManipulations(strip),
    Animation(strip, 8, 1, 6)
{
}

void CollMdl::init()
{
    ml = (_strip->numPixels() - 1) / 2;
    mr = ml + 1;
    newColors();
    clr = false;
}

void CollMdl::show()
{
    if (clr) {
        _strip->setPixelColor(l, 0);
        _strip->setPixelColor(r, 0);
        l--;
        r++;
        if (l < 0) {
            init();
            complete = true;
        }
        return;
    }

    // blend colors in the middle
    if ((mr - ml) > 1) {
        for (int i = ml; i < mr; ++i)
            BlendManipulations::blendPixel(i);
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
    complete = false;
}

void CollMdl::newColors()
{
    cl = ColorFromColorWheel(random(256));
    cr = ColorFromColorWheel(random(256));
    l = 0;
    r = _strip->numPixels() - 1;
}