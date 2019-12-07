#include "ChristmasWave.h"

#include "manipulation/ColorManipulation.h"

ChristmasWave::ChristmasWave(AbstractLedStrip* strip) :
    Animation(0xb000, strip, 5, 5),
    _currentStep(0)
{
}

auto ChristmasWave::IsQuadrant(byte quadrant) const -> bool
{
    return (_currentStep >> 2 & 0x3) == quadrant;
}

auto ChristmasWave::RedValue() const -> byte
{
    return IsQuadrant(0)
               ? (4 - _currentStep) * 63
               : IsQuadrant(3)
                     ? (_currentStep - 12) * 63
                     : 0;
}

auto ChristmasWave::GreenValue() const -> byte
{
    return IsQuadrant(1)
               ? (_currentStep - 4) * 63
               : IsQuadrant(2)
                     ? (12 - _currentStep) * 63
                     : 0;
}

auto ChristmasWave::CurrentColor() const -> uint32_t
{
    return ToColor(RedValue(), GreenValue(), 0);
}

auto ChristmasWave::Init() -> void
{
}

auto ChristmasWave::Advance() -> void
{
    _currentStep = (_currentStep + 1) % 16;
}

auto ChristmasWave::Show() -> void
{
    _crawl.SetNextColor(CurrentColor());
    _crawl.Step(_strip);

    Advance();
}
