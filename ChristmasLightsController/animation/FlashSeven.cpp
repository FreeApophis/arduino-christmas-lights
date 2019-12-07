#include "FlashSeven.h"

#include "manipulation/ColorManipulation.h"

FlashSeven::FlashSeven(AbstractLedStrip* strip) :
    Animation(0x0107, strip, 4, 8),
    _brightnessManipulation(strip),
    _current(0),
    _wheelIndex(0),
    _isForward(false),
    _changeDirection(0),
    _period(0)
{
}

auto FlashSeven::Init() -> void
{
    _wheelIndex = random(256);
    _isForward = random(2);
    _changeDirection = random(30, 100);
    _period = random(7, 20);
    _current = 0;
}

auto FlashSeven::Show() -> void
{
    _brightnessManipulation.ChangeAll(-64);

    const int pixelCount = _strip->numPixels();
    for (int index = _current; index < pixelCount; index += _period) {
        _brightnessManipulation.Change(index, -128);
    }

    if (_isForward)
        ++_current;
    else
        --_current;
    _current %= _period;

    const auto color = ColorFromColorWheel(_wheelIndex);
    _wheelIndex += 71;
    for (int index = _current; index < pixelCount; index += _period) {
        _strip->setPixelColor(index, color);
    }

    if (--_changeDirection < 0) {
        _changeDirection = random(70, 300);
        _isForward = !_isForward;
    }
}
