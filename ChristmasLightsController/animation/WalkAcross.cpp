#include "WalkAcross.h"

#include "manipulation/ColorManipulation.h"

WalkAcross::WalkAcross(AbstractLedStrip* strip) :
    Animation(0x011e, strip, 1, 6),
    _leftColor(0),
    _rightColor(0),
    _left(0),
    _right(0),
    _borderLeft(0),
    _borderRight(0)
{
}

auto WalkAcross::Init() -> void
{
    _borderLeft = _strip->numPixels() - 1;
    _borderRight = 0;

    _left = _borderRight;
    _right = _borderLeft;

    NewColors();
}

auto WalkAcross::Show() -> void
{
    // blend colors in the both ends
    if (_borderRight > 1) {
        for (auto index = 0; index < _borderRight; ++index) {
            _strip->setPixelColor(index, Shimmer(_strip->getPixelColor(index)));
        }
        for (uint16_t index = _borderLeft; index < _strip->numPixels(); ++index)
            _strip->setPixelColor(index, Shimmer(_strip->getPixelColor(index)));
    }

    // New colors are moving to the other end
    if (_left <= _borderLeft) {
        if (_left > (_borderRight + 1)) {
            _strip->setPixelColor(_left - 2, 0);
        }
        _strip->setPixelColor(_left, _leftColor);
    }
    if (_right >= _borderRight) {
        if (_right < (_borderLeft - 1)) {
            _strip->setPixelColor(_right + 2, 0);
        }
        _strip->setPixelColor(_right, _rightColor);
    }
    if ((_left >= _borderLeft) && (_right <= _borderRight)) {
        _borderLeft--;
        _borderRight++;
        if (_borderLeft < 0) {
            _needsClearance = true; // Force the strip clerance
            _complete = true;
            return;
        }
        Init();
        return;
    }
    _left++;
    _right--;
    _complete = false;
}

auto WalkAcross::NewColors() -> void
{
    _leftColor = ColorFromColorWheel(random(256));
    _rightColor = ColorFromColorWheel(random(256));
}
