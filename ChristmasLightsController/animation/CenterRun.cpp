#include "CenterRun.h"

#include "../Helper.h"

CenterRun::CenterRun(AbstractLedStrip* strip, byte duration):
    Animation(strip, duration, 4, 20),
    color(0),
    m(0),
    l(0),
    r(0)
{
}

void CenterRun::Init()
{
    color = ColorFromColorWheel(random(256));
    const int n = _strip->numPixels();
    const int diff = n >> 3;
    m = l = r = random(diff + 2) + ((n * 7) >> 4);
}

void CenterRun::Show()
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