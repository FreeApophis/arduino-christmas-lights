#include "CenterRun.h"

#include "manipulation/ColorManipulation.h"

CenterRun::CenterRun(AbstractLedStrip* strip) :
    Animation(0x0100, strip, 4, 20),
    _color(0),
    _middle(0),
    _difference(0)
{
}

auto CenterRun::MiddleWithVariations() const -> int
{
    const auto pixels = _strip->numPixels();
    const auto variation = pixels >> 3;

    return random(variation + 2) + (pixels * 7 >> 4);
}

auto CenterRun::SetParameters(const int middle) -> void
{
    _color = ColorFromColorWheel(random(256));

    _middle = middle;
    _difference = 0;
}

auto CenterRun::Init() -> void
{
    SetParameters(MiddleWithVariations());
}

auto CenterRun::IsFinished() const -> bool
{
    return _middle - _difference < 0
           && _middle + _difference >= _strip->numPixels();
}

auto CenterRun::Show() -> void
{
    // drawing pixels outside the strip is allowed ...
    _strip->setPixelColor(_middle - _difference, _color);
    _strip->setPixelColor(_middle + _difference, _color);

    _difference += 2;

    if (IsFinished()) {
        SetParameters(_middle + 1);
    }
}
