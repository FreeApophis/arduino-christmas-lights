#include "ClearFromCenter.h"

#include "manipulation/ColorManipulation.h"

ClearFromCenter::ClearFromCenter(AbstractLedStrip* strip) :
    Clearance(strip),
    color(0),
    _left(0),
    _right(0)
{
}

auto ClearFromCenter::Init() -> void
{
    _complete = false;
    color = ColorFromColorWheel(random(256));
    _left = _strip->numPixels() / 2;
    _right = _left + 1;
}

auto ClearFromCenter::Show() -> void
{
    if (_right < int(_strip->numPixels())) {
        _strip->setPixelColor(_right, color);
        if (_right > 0) {
            _strip->setPixelColor(_right - 1, 0);
        }
    }
    ++_right;
    if (_left >= 0) {
        _strip->setPixelColor(_left, color);
        if (_left < int(_strip->numPixels() - 1)) {
            _strip->setPixelColor(_left + 1, 0);
        }
    }
    --_left;
    _complete = (_left < 0);
}
