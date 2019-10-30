#include "RandomFill.h"

#include "../Helper.h"

RandomFill::RandomFill(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 15, 2, 4)
{
}

void RandomFill::init()
{
    w = random(256);
    remain = _strip->numPixels();
    clr = false;
    newDot(clr);
}

void RandomFill::show()
{
    char val = 12;
    if (clr)
        val = -12;
    if (BrightnessManipulation::change(pos, val)) {
        if (remain <= 0) {
            if (clr) {
                _strip->clear();
                w += 71;
                init();
                complete = true;
                return;
            } else {
                clr = true;
                remain = _strip->numPixels();
                newDot(clr);
            }
        } else {
            newDot(clr);
        }
    }
    complete = false;
}

void RandomFill::newDot(bool clr)
{
    uint32_t color = 0;
    if (!clr)
        color = ColorFromColorWheel(w);

    byte p = random(remain);
    byte c = 0;
    for (pos = 0; (pos < _strip->numPixels()) && (c < p); ++pos) {
        if (!color) {
            while (_strip->getPixelColor(pos) == 0)
                pos++;
            ++c;
        } else {
            while (_strip->getPixelColor(pos) != 0)
                pos++;
            ++c;
        }
    }
    if (!color) {
        while (_strip->getPixelColor(pos) == 0)
            pos++;
    } else {
        while (_strip->getPixelColor(pos) != 0)
            pos++;
    }
    if (pos >= _strip->numPixels()) { // something is wrong in the code
        for (uint16_t i = 0; i < _strip->numPixels(); ++i)
            _strip->setPixelColor(i, color);
        remain = 0;
    }
    BrightnessManipulation::setColor(color);
    remain--;
}