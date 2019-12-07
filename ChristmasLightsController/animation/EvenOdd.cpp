#include "EvenOdd.h"

#include "manipulation/ColorManipulation.h"

EvenOdd::EvenOdd(AbstractLedStrip* strip) :
    Animation(0x0106, strip, 10, 20),
    _leftColor(0),
    _rightColor(0),
    _left(0),
    _right(0)
{
}

auto EvenOdd::Init() -> void
{
    byte index = random(256);
    _leftColor = ColorFromColorWheel(index);
    index += random(4, 16);
    _rightColor = ColorFromColorWheel(index);
    _left = 0;
    _right = _strip->numPixels() - 1; // r is Odd
}

auto EvenOdd::Show() -> void
{
    _strip->setPixelColor(_left, _leftColor);
    _strip->setPixelColor(_right, _rightColor);
    _left += 2;
    _right -= 2;
    if (_right < 0) {
        if (_rightColor) {
            _rightColor = _leftColor = 0;
            _left = 0;
            _right = _strip->numPixels() - 1; // r is Odd
        } else {
            Init();
            _complete = true;
            return;
        }
    }
    _complete = false;
}
