#include "MergeWave.h"

#include "manipulation/ColorManipulation.h"

MergeWave::MergeWave(AbstractLedStrip* strip) :
    Animation(0x010c, strip, 3, 20),
    l(0),
    r(0),
    index(0),
    len(0)
{
}

void MergeWave::Init()
{
    l = 0;
    r = _strip->numPixels() - 1;
    index = random(256);
    len = random(8, 17);
    _strip->clear();
}

void MergeWave::Show()
{
    if (l < r) {
        _strip->setPixelColor(l, ColorFromColorWheel(l & 255));
        if (l > len)
            _strip->setPixelColor(l - len, 0);
        _strip->setPixelColor(r, ColorFromColorWheel((index + r) & 255));
        if ((r + len) > int(_strip->numPixels()))
            _strip->setPixelColor(r + len, 0);
    } else {
        uint32_t c = _strip->getPixelColor(l);
        c |= ColorFromColorWheel(l & 255);
        _strip->setPixelColor(l, c);
        c = _strip->getPixelColor(r);
        c |= ColorFromColorWheel((index + r) & 255);
        _strip->setPixelColor(r, c);
        _strip->setPixelColor(l - len, 0);
        _strip->setPixelColor(r + len, 0);
    }
    --r;
    ++l;
    index += 4;
    if (r < 0) { // Force the strip clerance
        _needsClearance = true;
        _complete = true;
    }
    _complete = false;
}