#include "ShineSeven.h"

#include "manipulation/ColorManipulation.h"

ShineSeven::ShineSeven(AbstractLedStrip* strip) :
    Animation(0x0117, strip, 4, 20),
    _brightnessManipulation(strip)
{
}

void ShineSeven::Init()
{
    curs = 0;
    w = random(256);
    base = random(4, 8);
    startNewColor();
}

void ShineSeven::Show()
{
    int n = _strip->numPixels();
    bool finish = true;
    for (int i = int(curs) - 1; i < n; i += base) { // Fade out previous color
        if (i >= 0)
            if (!_brightnessManipulation.change(i, -8))
                finish = false;
    }
    for (int i = curs; i < n; i += base) // Light up current color
        if (!_brightnessManipulation.change(i, 8))
            finish = false;
    if (finish) { // The current color has been light fully
        ++curs;
        if (curs >= base)
            curs = 0;
        startNewColor();
    }
}

void ShineSeven::startNewColor()
{
    uint32_t c = ColorFromColorWheel(w);
    w += 97;
    _brightnessManipulation.setColor(c);
    c &= 0x10101;
    for (uint16_t i = curs; i < _strip->numPixels(); i += base)
        _strip->setPixelColor(i, c);
}