#include "CenterRun.h"

#include "../Helper.h"

CenterRun::CenterRun(AbstractLedStrip* strip, byte duration):
    Animation(strip, duration, 4, 20)
{
}

void CenterRun::init()
{
    color = ColorFromColorWheel(random(256));
    int n = _strip->numPixels();
    int diff = n >> 3;
    m = l = r = random(diff + 2) + ((n * 7) >> 4);
}

void CenterRun::show()
{
    if (l >= 0)
        _strip->setPixelColor(l, color);
    if (r < int(_strip->numPixels()))
        _strip->setPixelColor(r, color);
    l -= 2;
    r += 2;
    if ((l < 0) && r >= int(_strip->numPixels())) {
        l = r = m + 1;
        color = ColorFromColorWheel(random(256));
    }
}