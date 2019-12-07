#include "RandomDrops.h"

#include "manipulation/ColorManipulation.h"

RandomDrops::RandomDrops(AbstractLedStrip* strip) :
    Animation(0x0113, strip, 2, 7),
    _brightnessManipulation(strip),
    _drops{},
    _count(0)
{
}

auto RandomDrops::Init() -> void
{
    _count = 0;
    Add();
}

auto RandomDrops::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    for (byte index = 0; index < _count; ++index) {
        if (++_drops[index].TimeFrame > 7) { // Delete old drops
            _drops[index].Position = _drops[byte(_count - 1)].Position;
            _drops[index].TimeFrame = _drops[byte(_count - 1)].TimeFrame;
            --_count;
            --index;
            continue;
        }
        auto position = _drops[index].Position - _drops[index].TimeFrame;
        if (position < 0) {
            position += pixelCount;
        }
        uint32_t c1 = _strip->getPixelColor(position + 1);
        _brightnessManipulation.Change(position + 1, -64);
        uint32_t c2 = _strip->getPixelColor(position);
        c2 = ColorSuperPosition(c1, c2);
        _strip->setPixelColor(position, c2);

        position = _drops[index].Position + _drops[index].TimeFrame;
        if (position >= pixelCount) {
            position -= pixelCount;
        }
        c1 = _strip->getPixelColor(position - 1);
        if (_drops[index].TimeFrame > 1) {
            _brightnessManipulation.Change(position - 1, -32);
        }
        c2 = _strip->getPixelColor(position);
        c2 = ColorSuperPosition(c1, c2);
        _strip->setPixelColor(position, c2);

        _brightnessManipulation.Change(_drops[index].Position, -64);
    }

    _brightnessManipulation.ChangeAll(-32);

    Add();
}

auto RandomDrops::Add() -> void
{
    if (_count >= 16) {
        return;
    }

    const auto position = random(_strip->numPixels());

    if (_strip->getPixelColor(position) != 0) {
        return;
    }

    const auto color = ColorFromColorWheel(random(256));
    _strip->setPixelColor(position, color);
    _drops[byte(_count)].Position = position;
    _drops[byte(_count)].TimeFrame = 0;
    _count++;
}
