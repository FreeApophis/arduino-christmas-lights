#include "Worms.h"
#include "../Helper.h"


Worms::Worms(AbstractLedStrip* strip):
    BrightnessManipulation(strip),
    Animation(strip, 9, 10, 20)
{
}

void Worms::Init()
{
    _active = 0;
    Add();
}

void Worms::Show()
{
    const int n = _strip->numPixels();

    // fade away
    BrightnessManipulation::changeAll(-32);

    // Move existing
    for (byte wi = 0; wi < _active; ++wi) {
        int np = _worms[wi].Position - 1;
        if (_worms[wi].Forward)
            np += 2;
        if ((np < 0) || (np >= n)) {
            Die(wi);
            --wi;
            continue;
        }
        uint32_t c = _strip->getPixelColor(np);
        if ((c != 0) && (random(10) == 0)) {
            Die(wi);
            --wi;
            continue;
        } else {
            c = ColorSuperPosition(c, _worms[wi].Color);
            _worms[wi].Position = np;
            _strip->setPixelColor(np, c);
        }
    }

    if (random(12) == 0)
        Add();
}

void Worms::Add()
{
    if (_active >= 5)
        return;

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
    if (_strip->getPixelColor(_worms[_active].Position) != 0)
        return;
    if (_worms[_active].Position < n / 3) {
        _worms[_active].Forward = true;
    } else if ((n - _worms[_active].Position) < n / 3) {
        _worms[_active].Forward = false;
    } else {
        _worms[_active].Forward = random(2);
    }
    ++_active;
}

void Worms::Die(const byte index)
{
    --_active;
    _worms[index].Color = _worms[_active].Color;
    _worms[index].Position = _worms[_active].Position;
    _worms[index].Forward = _worms[_active].Forward;
}