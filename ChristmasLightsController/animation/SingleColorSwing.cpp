#include "SingleColorSwing.h"

#include "manipulation/ColorManipulation.h"

SingleColorSwing::SingleColorSwing(AbstractLedStrip* strip) :
    Animation(0x0118, strip, 3, 10),
    _color(0),
    _length(0),
    _index(0),
    _isForward(false),
    _wheelIndex(0)
{
}

auto SingleColorSwing::Init() -> void
{
    _length = 1;
    _wheelIndex = random(256);
    _color = ColorFromColorWheel(_wheelIndex);
    _strip->setPixelColor(0, _color);
    _isForward = true;
    _index = _length;
}

auto SingleColorSwing::Show() -> void
{
    if (_isForward) {
        for (int index = 0; index <= _index; ++index) {
            if (index < (_index - _length)) {
                _strip->setPixelColor(index, 0);
            } else {
                _strip->setPixelColor(index, _color);
            }
        }
        ++_index;
        if (_index >= int(_strip->numPixels())) {
            _isForward = false;
            _length += random(1, _strip->numPixels() >> 4);
            _index = _strip->numPixels() - _length - 1;
            _wheelIndex += 4;
        }
    } else {
        for (auto index = _strip->numPixels() - 1; index >= _index; --index) {
            if (index > (_index + _length)) {
                _strip->setPixelColor(index, 0);
            } else {
                _strip->setPixelColor(index, _color);
            }
        }
        --_index;
        if (_index < 0) {
            _isForward = true;
            _index = _length;
            _wheelIndex += 4;
        }
    }
    if (_length >= int(_strip->numPixels())) {
        _needsClearance = true; // Force the strip clerance
        _complete = true;
        return;
    }
    _complete = false;
}
