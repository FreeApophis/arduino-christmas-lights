#include "ShineSeven.h"

#include "../Helper.h"

ShineSeven::ShineSeven(AbstractLedStrip* strip, byte duration) :
    BrightnessManipulation(strip),
    Animation(strip, 12, 4, 20)
{
}

void ShineSeven::init()
{
    curs = 0;
    w = random(256);
    base = random(4, 8);
    startNewColor();
}

void ShineSeven::show()
{
    int n = _strip->numPixels();
    bool finish = true;
    for (int i = int(curs) - 1; i < n; i += base) { // Fade out previous color
        if (i >= 0)
            if (!BrightnessManipulation::change(i, -8))
                finish = false;
    }
    for (int i = curs; i < n; i += base) // Light up current color
        if (!BrightnessManipulation::change(i, 8))
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
    BrightnessManipulation::setColor(c);
    c &= 0x10101;
    for (uint16_t i = curs; i < _strip->numPixels(); i += base)
        _strip->setPixelColor(i, c);
}