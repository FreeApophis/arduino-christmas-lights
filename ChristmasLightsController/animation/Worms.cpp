#include "Worms.h"

#include "manipulation/ColorManipulation.h"

Worms::Worms(AbstractLedStrip* strip) :
    Animation(0x0121, strip, 10, 20),
    _brightnessManipulation(strip),
    _worms{},
    _active(0)
{
}

auto Worms::Init() -> void
{
    _active = 0;
    Add();
}

auto Worms::Show() -> void
{
    const int n = _strip->numPixels();

    // fade away
    _brightnessManipulation.ChangeAll(-32);

    // Move existing
    for (byte wormIndex = 0; wormIndex < _active; ++wormIndex) {
        int newPosition = _worms[wormIndex].Position - 1;
        if (_worms[wormIndex].Forward)
            newPosition += 2;
        if ((newPosition < 0) || (newPosition >= n)) {
            Die(wormIndex);
            --wormIndex;
            continue;
        }
        uint32_t color = _strip->getPixelColor(newPosition);
        if ((color != 0) && (random(10) == 0)) {
            Die(wormIndex);
            --wormIndex;
        } else {
            color = ColorSuperPosition(color, _worms[wormIndex].Color);
            _worms[wormIndex].Position = newPosition;
            _strip->setPixelColor(newPosition, color);
        }
    }

    if (random(12) == 0)
        Add();
}

auto Worms::Add() -> void
{
    if (_active >= 5) {
        return;
    }

    const byte mode = random(3);
    const int n = _strip->numPixels();
    switch (mode) {
        case 0: // Run from the start
            _worms[_active].Position = 0;
            break;
        case 1: // Run from the end
            _worms[_active].Position = n - 1;
            break;
        case 2: // Run from the random position
        default:
            _worms[_active].Position = random(n);
            break;
    }
    _worms[_active].Color = ColorFromColorWheel(random(256));
    if (_strip->getPixelColor(_worms[_active].Position) != 0) {
        return;
    }
    if (_worms[_active].Position < n / 3) {
        _worms[_active].Forward = true;
    } else if ((n - _worms[_active].Position) < n / 3) {
        _worms[_active].Forward = false;
    } else {
        _worms[_active].Forward = random(2);
    }
    ++_active;
}

auto Worms::Die(const byte index) -> void
{
    --_active;
    _worms[index].Color = _worms[_active].Color;
    _worms[index].Position = _worms[_active].Position;
    _worms[index].Forward = _worms[_active].Forward;
}
