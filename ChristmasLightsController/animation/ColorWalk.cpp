#include "ColorWalk.h"

#include "manipulation/ColorManipulation.h"

#include "framework.h"

ColorWalk::ColorWalk(AbstractLedStrip* strip) :
    Animation(0x0103, strip, 4, 12),
    _index(0),
    _period(0),
    _isForward(false),
    _wheelIndex(0)
{
}

auto ColorWalk::Init() -> void
{
    _index = 0;
    _wheelIndex = random(256);
    _isForward = random(2);
    _period = random(10, 30);
}

auto ColorWalk::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    if (_isForward) {
        if (_index > pixelCount) {
            _index -= _period;
            _strip->setPixelColor(pixelCount - 1, 0);
        }
        const auto color = ColorFromColorWheel(_wheelIndex--);
        for (auto index = _index; index > 0; index -= _period) {
            if (index > 0)
                _strip->setPixelColor(index - 1, 0);
            _strip->setPixelColor(index, color);
        }
        ++_index;
    } else {
        if (_index < 0) {
            _index += _period;
            _strip->setPixelColor(0, 0);
        }
        const auto color = ColorFromColorWheel(_wheelIndex++);
        for (auto index = _index; index < pixelCount; index += _period) {
            if (index < int(_strip->numPixels() - 1))
                _strip->setPixelColor(index + 1, 0);
            _strip->setPixelColor(index, color);
        }
        --_index;
    }
}
