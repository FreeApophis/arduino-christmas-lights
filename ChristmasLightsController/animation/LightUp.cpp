#include "LightUp.h"

LightUp::LightUp(AbstractLedStrip* strip) :
    Animation(0x010a, strip, 6, 24),
    _brightnessManipulation(strip),
    _speed(0),
    _increment(0)
{
}

auto LightUp::Init() -> void
{
    _speed = 1;
    _increment = _speed;
    NewColor();
}

auto LightUp::Show() -> void
{
    const auto finish = _brightnessManipulation.ChangeAll(_increment);
    if (finish) {
        if (_increment > 0)
            _increment = -8;
        else {
            ++_speed;
            _increment = _speed;
            if (_speed > 8) {
                _speed = 1;
                NewColor();
            }
        }
    }
}

auto LightUp::NewColor() -> void
{
    uint32_t color = 0;
    for (byte index = 0; index < 3; ++index) {
        color <<= 8;
        const byte digit = random(16) << 4;
        color |= digit;
    }
    _brightnessManipulation.SetColor(color);
}
