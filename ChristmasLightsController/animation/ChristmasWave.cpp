#include "ChristmasWave.h"

#include "manipulation/ColorManipulation.h"

ChristmasWave::ChristmasWave(AbstractLedStrip* strip, const byte duration) :
    Animation(0xb000, strip, duration, 5, 5),
    _step(0)
{
}

bool ChristmasWave::IsQuadrant(byte quadrant) const
{
    return (_step >> 2 & 0x3) == quadrant;
}

byte ChristmasWave::RedValue() const
{
    return IsQuadrant(0)
               ? (4 - _step) * 63
               : IsQuadrant(3)
                     ? (_step - 12) * 63
                     : 0;
}

byte ChristmasWave::GreenValue() const
{
    return IsQuadrant(1)
               ? (_step - 4) * 63
               : IsQuadrant(2)
                     ? (12 - _step) * 63
                     : 0;
}

uint32_t ChristmasWave::CurrentColor() const
{
    return ToColor(RedValue(), GreenValue(), 0);
}

void ChristmasWave::Init()
{
    for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
        _strip->setPixelColor(index, CurrentColor());
    }
}

void ChristmasWave::Advance()
{
    _step = (_step + 1) % 16;
}

void ChristmasWave::Show()
{
    _crawl.SetNextColor(CurrentColor());
    _crawl.Step(_strip);

    Advance();
}
