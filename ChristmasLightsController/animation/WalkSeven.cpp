#include "WalkSeven.h"

#include "manipulation/ColorManipulation.h"

WalkSeven::WalkSeven(AbstractLedStrip* strip) :
    Animation(0x011f, strip, 8, 15),
    _brightnessManipulation(strip),
    _current(0),
    _wheelIndex(0),
    _isForward(false),
    _changeDirection(0),
    _period(0)
{
}

auto WalkSeven::Init() -> void
{
    _wheelIndex = random(256);
    _isForward = random(2);
    _changeDirection = random(30, 100);
    _period = random(13, 20);
    _current = 0;
}

auto WalkSeven::Show() -> void
{
    _brightnessManipulation.ChangeAll(-64);

    const int pixelCount = _strip->numPixels();
    const uint32_t color1 = ColorFromColorWheel(_wheelIndex);
    _wheelIndex += 71;
    for (int index = _current; index < pixelCount; index += _period) {
        uint32_t color2 = _strip->getPixelColor(index);
        color2 = ColorSuperPosition(color1, color2);
        _strip->setPixelColor(index, color2);
    }

    if (_isForward)
        ++_current;
    else
        --_current;
    _current %= _period;

    if (--_changeDirection < 0) {
        _changeDirection = random(70, 300);
        _isForward = !_isForward;
    }
}
