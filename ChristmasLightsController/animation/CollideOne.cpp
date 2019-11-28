#include "CollideOne.h"

#include "ColorManipulation.h"

CollideOne::CollideOne(AbstractLedStrip* strip) :
    Animation(0x0101, strip, 2, 1, 3),
    _leftColor(0),
    _rightColor(0),
    _left(0),
    _right(0),
    _isBooom(false)
{
}

void CollideOne::Init()
{
    _left = 0;
    _right = _strip->numPixels() - 1;
    byte w = random(256);
    _leftColor = ColorFromColorWheel(w);
    w += random(8, 16);
    _rightColor = ColorFromColorWheel(w);
    _strip->clear();
    _isBooom = false;
}

void CollideOne::Show()
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