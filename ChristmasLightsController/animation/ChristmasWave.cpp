#include "ChristmasWave.h"

#include "manipulation/ColorManipulation.h"

ChristmasWave::ChristmasWave(AbstractLedStrip* strip) :
    Animation(0xb000, strip, 5, 5),
    _currentStep(0)
{
}

bool ChristmasWave::IsQuadrant(byte quadrant) const
{
    return (_currentStep >> 2 & 0x3) == quadrant;
}

byte ChristmasWave::RedValue() const
{
    return IsQuadrant(0)
               ? (4 - _currentStep) * 63
               : IsQuadrant(3)
                     ? (_currentStep - 12) * 63
                     : 0;
}

byte ChristmasWave::GreenValue() const
{
    return IsQuadrant(1)
               ? (_currentStep - 4) * 63
               : IsQuadrant(2)
                     ? (12 - _currentStep) * 63
                     : 0;
}

uint32_t ChristmasWave::CurrentColor() const
{
    return ToColor(RedValue(), GreenValue(), 0);
}

void ChristmasWave::Init()
{
}

void ChristmasWave::Advance()
{
    _currentStep = (_currentStep + 1) % 16;
}

void ChristmasWave::Show()
{
    _crawl.SetNextColor(CurrentColor());
    _crawl.Step(_strip);

    Advance();
}
