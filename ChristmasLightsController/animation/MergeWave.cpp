#include "MergeWave.h"

#include "manipulation/Clear.h"
#include "manipulation/ColorManipulation.h"

MergeWave::MergeWave(AbstractLedStrip* strip) :
    Animation(0x010c, strip, 3, 20),
    _left(0),
    _right(0),
    _index(0),
    _length(0)
{
}

auto MergeWave::Init() -> void
{
    _left = 0;
    _right = _strip->numPixels() - 1;
    _index = random(256);
    _length = random(8, 17);
    Clear(_strip);
}

auto MergeWave::Show() -> void
{
    if (_left < _right) {
        _strip->setPixelColor(_left, ColorFromColorWheel(_left & 255));
        if (_left > _length)
            _strip->setPixelColor(_left - _length, 0);
        _strip->setPixelColor(_right, ColorFromColorWheel((_index + _right) & 255));
        if (_right + _length > int(_strip->numPixels()))
            _strip->setPixelColor(_right + _length, 0);
    } else {
        auto c = _strip->getPixelColor(_left);
        c |= ColorFromColorWheel(_left & 255);
        _strip->setPixelColor(_left, c);
        c = _strip->getPixelColor(_right);
        c |= ColorFromColorWheel((_index + _right) & 255);
        _strip->setPixelColor(_right, c);
        _strip->setPixelColor(_left - _length, 0);
        _strip->setPixelColor(_right + _length, 0);
    }
    --_right;
    ++_left;
    _index += 4;
    if (_right < 0) { // Force the strip clerance
        _needsClearance = true;
        _complete = true;
    }
    _complete = false;
}
