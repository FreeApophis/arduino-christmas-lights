#include "ClearSide.h"

#include "manipulation/ColorManipulation.h"

ClearSide::ClearSide(AbstractLedStrip* strip) :
    Clearance(strip)
{
}

auto ClearSide::Init() -> void
{
    _complete = false;
    _color = ColorFromColorWheel(random(256));
    _isForward = random(2);
    if (_isForward) {
        _index = 0;
    } else {
        _index = _strip->numPixels() - 1;
    }
}

auto ClearSide::Show() -> void
{
    if (_isForward) {
        if (_index < int(_strip->numPixels())) {
            _strip->setPixelColor(_index, _color);
            if (_index > 0) {
                _strip->setPixelColor(_index - 1, 0);
            }
        }
        ++_index;
        _complete = (_index >= int(_strip->numPixels()));
    } else {
        if (_index >= 0) {
            _strip->setPixelColor(_index, _color);
            if (_index < int(_strip->numPixels() - 1)) {
                _strip->setPixelColor(_index + 1, 0);
            }
        }
        --_index;
        _complete = (_index < 0);
    }
}
