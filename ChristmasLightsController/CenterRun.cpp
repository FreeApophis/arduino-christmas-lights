#include "CenterRun.h"

#include "Helper.h"

CenterRun::CenterRun(AbstractLedStrip* strip, byte duration) :
    Animation(strip, duration, 4, 20),
    _color(0),
    _left(0),
    _middle(0),
    _right(0)
{
}

void CenterRun::Init()
{
    _color = ColorFromColorWheel(random(256));
    const int n = _strip->numPixels();
    const int diff = n >> 3;
    _middle = _left = _right = random(diff + 2) + ((n * 7) >> 4);
}

void CenterRun::Show()
{
    if (_left >= 0) {
        _strip->setPixelColor(_left, _color);
    }
    if (_right < int(_strip->numPixels())) {
        _strip->setPixelColor(_right, _color);
    }
    _left -= 2;
    _right += 2;
    if ((_left < 0) && _right >= int(_strip->numPixels())) {
        _left = _right = _middle + 1;
        _color = ColorFromColorWheel(random(256));
    }
}