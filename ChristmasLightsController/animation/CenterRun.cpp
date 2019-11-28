#include "CenterRun.h"

#include "ColorManipulation.h"

CenterRun::CenterRun(AbstractLedStrip* strip, byte duration) :
    Animation(0x0100, strip, duration, 4, 20),
    _color(0),
    _middle(0),
    _difference(0)
{
}

int CenterRun::MiddleWithVariations() const
{
    const int pixels = _strip->numPixels();
    const int variation = pixels >> 3;

    return random(variation + 2) + ((pixels * 7) >> 4);
}

void CenterRun::SetParameters(const int middle)
{
    _color = ColorFromColorWheel(random(256));

    _middle = middle;
    _difference = 0;
}

void CenterRun::Init()
{
    SetParameters(MiddleWithVariations());
}

bool CenterRun::IsFinished() const
{
    return _middle - _difference < 0
           && _middle + _difference >= _strip->numPixels();
}

void CenterRun::Show()
{
    // drawing pixels outside the strip is allowed ...
    _strip->setPixelColor(_middle - _difference, _color);
    _strip->setPixelColor(_middle + _difference, _color);

    _difference += 2;

    if (IsFinished()) {
        SetParameters(_middle + 1);
    }
}
