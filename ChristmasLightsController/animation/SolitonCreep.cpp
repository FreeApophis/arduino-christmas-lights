#include "SolitonCreep.h"

#include "manipulation/ColorManipulation.h"

#include <cstdlib>

SolitonCreep::SolitonCreep(AbstractLedStrip* strip) :
    Animation(0x011a, strip, 6, 14),
    _space(0),
    _changeDirection(0),
    _dots{},
    _solitons(0),
    _wheelIndex(0)
{
}

auto SolitonCreep::Init() -> void
{
    _wheelIndex = random(256);
    _crawl.SetDirection(RandomDirection());
    _changeDirection = random(200, 500);
    NewSoliton();
}

auto SolitonCreep::Show() -> void
{
    _crawl.Step(_strip);

    if (--_changeDirection <= 0) {
        _crawl.ToggleDirection();
        _changeDirection = random(200, 500);
    }

    const int pos = StartPosition(_crawl.GetDirection(), _strip->numPixels() - 1);

    if (_solitons <= 4) {
        const int index = abs(_solitons);
        _strip->setPixelColor(pos, _dots[index]);
        ++_solitons;
    } else {
        if (--_space >= 0) {
            _strip->setPixelColor(pos, 0);
        } else {
            NewSoliton();
        }
    }
}

auto SolitonCreep::NewSoliton() -> void
{
    _solitons = -3;
    const uint32_t color = ColorFromColorWheel(_wheelIndex);
    _dots[0] = color;
    _wheelIndex += 71;
    uint32_t red = ExtractRed(color);
    uint32_t green = ExtractGreen(color);
    uint32_t blue = ExtractBlue(color);
    for (byte index = 1; index <= 4; ++index) {
        red >>= 1;
        green >>= 1;
        blue >>= 1;
        auto cc = blue & 0xff;
        cc <<= 8;
        cc |= green & 0xff;
        cc <<= 8;
        cc |= red & 0xff;
        _dots[index] = cc;
    }
    _space = random(3, 10);

    const auto position = StartPosition(_crawl.GetDirection(), _strip->numPixels() - 1);

    _strip->setPixelColor(position, _dots[4]);
}
