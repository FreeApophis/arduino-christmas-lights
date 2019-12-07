#include "LightHouse.h"

LightHouse::LightHouse(AbstractLedStrip* strip) :
    Animation(0x0109, strip, 2, 10),
    _brightnessManipulation(strip),
    _position(0),
    _step(0),
    _increment(0),
    _speed(0),
    _delay(0)
{
}

auto LightHouse::Init() -> void
{
    uint32_t color = 0xff;
    for (byte index = 0; index <= 4; ++index) {
        _dots[index] = color | (color << 8) | (color << 16);
        color >>= 1;
    }
    _brightnessManipulation.SetColor(_dots[4]);
    _position = random(_strip->numPixels());
    _step = 0;
    _speed = random(1, 4);
    _delay = _speed;
}

auto LightHouse::Show() -> void
{
    _brightnessManipulation.ChangeAll(-8);
    if (--_delay > 0)
        return;
    _delay = _speed;

    const int pixelCount = _strip->numPixels();
    if (_step <= 0) {
        _increment = 1;
        if (_position > pixelCount / 2)
            _increment = -1;
        _step = random(5, pixelCount);
        _speed += random(3) - 1;
        if (_speed < 1)
            _speed = 1;
        else if (_speed > 3)
            _speed = 3;
    }
    _position += _increment;
    _position %= pixelCount;

    for (auto index = 0; index <= 5; ++index) {
        byte lastIndex = index;
        if (lastIndex >= 1)
            lastIndex--;
        int x = _position + index;
        if (x >= pixelCount)
            x -= pixelCount;
        else if (x < 0)
            x += pixelCount;
        _strip->setPixelColor(x, _dots[lastIndex]);
        x = _position - index;
        if (x >= pixelCount)
            x -= pixelCount;
        else if (x < 0)
            x += pixelCount;
        _strip->setPixelColor(x, _dots[lastIndex]);
    }
    _step--;
}
