#include "WalkToCenter.h"

#include "manipulation/ColorManipulation.h"

WalkToCenter::WalkToCenter(AbstractLedStrip* strip) :
    Animation(0x0120, strip, 1, 6),
    _colorLeft(0),
    _colorRight(0),
    _left(0),
    _right(0),
    _leftMiddle(0),
    _rightMiddle(0),
    _clear(false)
{
}

auto WalkToCenter::Init() -> void
{
    _leftMiddle = (_strip->numPixels() - 1) / 2;
    _rightMiddle = _leftMiddle + 1;
    NewColors();
    _clear = false;
}

auto WalkToCenter::Show() -> void
{
    if (_clear) {
        _strip->setPixelColor(_left, 0);
        _strip->setPixelColor(_right, 0);
        _left--;
        _right++;
        if (_left < 0) {
            Init();
            _complete = true;
        }
        return;
    }

    // blend colors in the middle
    if ((_rightMiddle - _leftMiddle) > 1) {
        for (int index = _leftMiddle; index < _rightMiddle; ++index) {
            _strip->setPixelColor(index, Shimmer(_strip->getPixelColor(index)));
        }
    }

    // New colors are moving to the center
    if (_left <= _leftMiddle) {
        if (_left > 1)
            _strip->setPixelColor(_left - 2, 0);
        _strip->setPixelColor(_left, _colorLeft);
    }
    if (_right >= _rightMiddle) {
        if (_right < int(_strip->numPixels() - 2))
            _strip->setPixelColor(_right + 2, 0);
        _strip->setPixelColor(_right, _colorRight);
    }
    if ((_left >= _leftMiddle) && (_right <= _rightMiddle)) {
        _leftMiddle--;
        _rightMiddle++;
        if (_leftMiddle < 0) {
            _clear = true;
            _left = (_strip->numPixels() - 1) / 2;
            _right = _left + 1;
            return;
        }
        NewColors();
        return;
    }
    _left++;
    _right--;
    _complete = false;
}

auto WalkToCenter::NewColors() -> void
{
    _colorLeft = ColorFromColorWheel(random(256));
    _colorRight = ColorFromColorWheel(random(256));
    _left = 0;
    _right = _strip->numPixels() - 1;
}
