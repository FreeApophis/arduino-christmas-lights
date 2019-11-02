#include "CollEnd.h"

#include "ColorManipulation.h"

CollEnd::CollEnd(AbstractLedStrip* strip, byte duration) :
    Animation(strip, 10, 1, 6),
    _leftColor(0),
    _rightColor(0),
    _left(0),
    _right(0),
    _borderLeft(0),
    _border_right(0)
{
}

void CollEnd::Init()
{
    _borderLeft = _strip->numPixels() - 1;
    _border_right = 0;
    newColors();
}

void CollEnd::Show()
{
    // blend colors in the both ends
    if (_border_right > 1) {
        for (int i = 0; i < _border_right; ++i) {
            _strip->setPixelColor(i, Shimmer(_strip->getPixelColor(i)));
        }
        for (uint16_t i = _borderLeft; i < _strip->numPixels(); ++i)
            _strip->setPixelColor(i, Shimmer(_strip->getPixelColor(i)));
    }

    // New colors are moving to the other end
    if (_left <= _borderLeft) {
        if (_left > (_border_right + 1))
            _strip->setPixelColor(_left - 2, 0);
        _strip->setPixelColor(_left, _leftColor);
    }
    if (_right >= _border_right) {
        if (_right < (_borderLeft - 1))
            _strip->setPixelColor(_right + 2, 0);
        _strip->setPixelColor(_right, _rightColor);
    }
    if ((_left >= _borderLeft) && (_right <= _border_right)) {
        _borderLeft--;
        _border_right++;
        if (_borderLeft < 0) {
            _needsClear = true; // Force the strip clerance
            _complete = true;
            return;
        }
        newColors();
        return;
    }
    _left++;
    _right--;
    _complete = false;
}

void CollEnd::newColors()
{
    _leftColor = ColorFromColorWheel(random(256));
    _rightColor = ColorFromColorWheel(random(256));
    _left = _border_right;
    _right = _borderLeft;
}
