#include "RandomFill.h"

#include "manipulation/Clear.h"
#include "manipulation/ColorManipulation.h"

RandomFill::RandomFill(AbstractLedStrip* strip) :
    Animation(0x0115, strip, 2, 4),
    _brightnessManipulation(strip),
    _wheelIndex(0),
    _remaining(0),
    _position(0),
    _isClear(false)
{
}

auto RandomFill::Init() -> void
{
    _wheelIndex = random(256);
    _remaining = _strip->numPixels();
    _isClear = false;
    NewDot(_isClear);
}

auto RandomFill::Show() -> void
{
    char val = 12;
    if (_isClear)
        val = -12;
    if (_brightnessManipulation.Change(_position, val)) {
        if (_remaining <= 0) {
            if (_isClear) {
                Clear(_strip);
                _wheelIndex += 71;
                Init();
                _complete = true;
                return;
            } else {
                _isClear = true;
                _remaining = _strip->numPixels();
                NewDot(_isClear);
            }
        } else {
            NewDot(_isClear);
        }
    }
    _complete = false;
}

auto RandomFill::NewDot(const bool clear) -> void
{
    uint32_t color = 0;
    if (!clear) {
        color = ColorFromColorWheel(_wheelIndex);
    }

    const byte p = random(_remaining);
    byte c = 0;
    for (_position = 0; (_position < _strip->numPixels()) && (c < p); ++_position) {
        if (!color) {
            while (_strip->getPixelColor(_position) == 0)
                _position++;
            ++c;
        } else {
            while (_strip->getPixelColor(_position) != 0)
                _position++;
            ++c;
        }
    }
    if (!color) {
        while (_strip->getPixelColor(_position) == 0)
            _position++;
    } else {
        while (_strip->getPixelColor(_position) != 0)
            _position++;
    }
    if (_position >= _strip->numPixels()) { // something is wrong in the code
        for (uint16_t index = 0; index < _strip->numPixels(); ++index)
            _strip->setPixelColor(index, color);
        _remaining = 0;
    }
    _brightnessManipulation.SetColor(color);
    _remaining--;
}
