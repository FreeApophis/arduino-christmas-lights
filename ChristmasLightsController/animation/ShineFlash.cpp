#include "ShineFlash.h"

#include "../Helper.h"

ShineFlash::ShineFlash(AbstractLedStrip* strip, byte duration):
    BrightnessManipulation(strip),
    Animation(strip, 12, 4, 20)
{
}

void ShineFlash::Init()
{
    w = random(256);
    mode = 0;
    flash = false;
    startNewColor();
}

void ShineFlash::Show()
{
    int n = _strip->numPixels();
    bool finish = true;
    switch (mode) {
        case 0: // Light up
            finish = BrightnessManipulation::changeAll(4);
            if (finish) {
                flash = true;
                remain = random(17, 30);
                wait = 0;
            }
            break;
        case 1:          // Run flash
            if (flash) { // Lit the LED
                if (--wait > 0)
                    return;
                wait = random(2, 7);
                indx = random(n);
                if (remain > 0) {
                    uint32_t c = _strip->getPixelColor(indx);
                    c |= 0x808080;
                    _strip->setPixelColor(indx, c);
                    flash = false;
                    remain--;
                } else {
                    mode++;
                }
            } else {
                uint32_t c = _strip->getPixelColor(indx);
                c &= 0x7f7f7f;
                _strip->setPixelColor(indx, c);
                flash = true;
            }
            finish = false;
            break;
        case 2: // Fade out
        default:
            finish = BrightnessManipulation::changeAll(-4);
            break;
    }

    if (finish) { // The current color has been light fully
        ++mode;
        if (mode >= 3) {
            startNewColor();
            mode = 0;
            _complete = true;
            return;
        }
    }
    _complete = false;
}

void ShineFlash::startNewColor()
{
    uint32_t c = ColorFromColorWheel(w);
    c &= 0x7f7f7f;
    w += 17;
    BrightnessManipulation::setColor(c);
    c &= 0x10101;
    int n = _strip->numPixels();
    for (int i = 0; i < n; ++i)
        _strip->setPixelColor(i, c);
}