#include "MergeOne.h"

#include "manipulation/Clear.h"
#include "manipulation/ColorManipulation.h"

MergeOne::MergeOne(AbstractLedStrip* strip) :
    Animation(0x010b, strip, 8, 30),
    _leftColor(0),
    _rightColor(0),
    _left(0),
    _right(0)
{
}

auto MergeOne::Init() -> void
{
    _left = 0;
    _right = _strip->numPixels();
    byte wheelIndex = random(256);
    _leftColor = ColorFromColorWheel(wheelIndex);
    wheelIndex += random(4, 16);
    _rightColor = ColorFromColorWheel(wheelIndex);
    Clear(_strip);
}

auto MergeOne::Show() -> void
{
    if (_left < _right) {
        _strip->setPixelColor(_left, _leftColor);
        _strip->setPixelColor(_right, _rightColor);
    } else {
        uint32_t color = _strip->getPixelColor(_left);
        color = ColorSuperPosition(color, _leftColor);
        _strip->setPixelColor(_left, color);
        color = _strip->getPixelColor(_right);
        color = ColorSuperPosition(color, _rightColor);
        _strip->setPixelColor(_right, color);
    }

    --_right;
    ++_left;
    if (_right < 0) { // Force the strip clerance
        _needsClearance = true;
        _complete = true;
        return;
    }
    _complete = false;
}
