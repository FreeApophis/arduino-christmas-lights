#include "SingleColorSwing.h"

#include "manipulation/ColorManipulation.h"

SingleColorSwing::SingleColorSwing(AbstractLedStrip* strip) :
    Animation(0x0118, strip, 10, 3, 10)
{
}

void SingleColorSwing::Init()
{
    len = 1;
    w = random(256);
    color = ColorFromColorWheel(w);
    _strip->setPixelColor(0, color);
    fwd = true;
    index = len;
}

void SingleColorSwing::Show()
{
    if (fwd) {
        for (int i = 0; i <= index; ++i) {
            if (i < (index - len))
                _strip->setPixelColor(i, 0);
            else
                _strip->setPixelColor(i, color);
        }
        ++index;
        if (index >= int(_strip->numPixels())) {
            fwd = false;
            len += random(1, _strip->numPixels() >> 4);
            index = _strip->numPixels() - len - 1;
            w += 4;
        }
    } else {
        for (int i = _strip->numPixels() - 1; i >= index; --i) {
            if (i > (index + len))
                _strip->setPixelColor(i, 0);
            else
                _strip->setPixelColor(i, color);
        }
        --index;
        if (index < 0) {
            fwd = true;
            index = len;
            w += 4;
        }
    }
    if (len >= int(_strip->numPixels())) {
        _needsClearance = true; // Force the strip clerance
        _complete = true;
        return;
    }
    _complete = false;
}