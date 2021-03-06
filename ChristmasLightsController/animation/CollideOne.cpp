#include "CollideOne.h"

#include "manipulation/Clear.h"
#include "manipulation/ColorManipulation.h"

CollideOne::CollideOne(AbstractLedStrip* strip) :
    Animation(0x0101, strip, 1, 3),
    _leftColor(0),
    _rightColor(0),
    _left(0),
    _right(0),
    _isBooom(false)
{
}

auto CollideOne::Init() -> void
{
    _left = 0;
    _right = _strip->numPixels() - 1;
    byte w = random(256);
    _leftColor = ColorFromColorWheel(w);
    w += random(8, 16);
    _rightColor = ColorFromColorWheel(w);
    Clear(_strip);
    _isBooom = false;
}

auto CollideOne::Show() -> void
{
    if (_isBooom) {
        _strip->setPixelColor(_left, 0xffffff);
        _strip->setPixelColor(_right, 0xffffff);
        if ((_right - _left) >= 12) {
            _strip->setPixelColor(_left + 6, 0);
            _strip->setPixelColor(_right - 6, 0);
        }
        --_left;
        ++_right;
        if (_left < 0) {
            Init();
            _complete = true;
            return;
        }
    } else {
        if (_left < _right) {
            _strip->setPixelColor(_left, _leftColor);
            _strip->setPixelColor(_right, _rightColor);
            --_right;
            ++_left;
        } else {
            _isBooom = true;
        }
    }
    _complete = false;
}
