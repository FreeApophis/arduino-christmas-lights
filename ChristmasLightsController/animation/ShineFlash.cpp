#include "ShineFlash.h"

#include "manipulation/ColorManipulation.h"

ShineFlash::ShineFlash(AbstractLedStrip* strip) :
    Animation(0x0116, strip, 4, 20),
    _brightnessManipulation(strip),
    _wheelIndex(0),
    _mode(0),
    _isFlash(false),
    _remaining(0),
    _index(0),
    _wait(0)
{
}

auto ShineFlash::Init() -> void
{
    _wheelIndex = random(256);
    _mode = 0;
    _isFlash = false;
    StartNewColor();
}

auto ShineFlash::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    bool finish;
    switch (_mode) {
        case 0: // Light up
            finish = _brightnessManipulation.ChangeAll(4);
            if (finish) {
                _isFlash = true;
                _remaining = random(17, 30);
                _wait = 0;
            }
            break;
        case 1:             // Run flash
            if (_isFlash) { // Lit the LED
                if (--_wait > 0)
                    return;
                _wait = random(2, 7);
                _index = random(pixelCount);
                if (_remaining > 0) {
                    uint32_t c = _strip->getPixelColor(_index);
                    c |= 0x808080;
                    _strip->setPixelColor(_index, c);
                    _isFlash = false;
                    _remaining--;
                } else {
                    _mode++;
                }
            } else {
                uint32_t c = _strip->getPixelColor(_index);
                c &= 0x7f7f7f;
                _strip->setPixelColor(_index, c);
                _isFlash = true;
            }
            finish = false;
            break;
        case 2: // Fade out
        default:
            finish = _brightnessManipulation.ChangeAll(-4);
            break;
    }

    if (finish) { // The current color has been light fully
        ++_mode;
        if (_mode >= 3) {
            StartNewColor();
            _mode = 0;
            _complete = true;
            return;
        }
    }
    _complete = false;
}

auto ShineFlash::StartNewColor() -> void
{
    auto color = ColorFromColorWheel(_wheelIndex);
    color &= 0x7f7f7f;
    _wheelIndex += 17;
    _brightnessManipulation.SetColor(color);
    color &= 0x10101;

    for (int index = 0; index < _strip->numPixels(); ++index) {
        _strip->setPixelColor(index, color);
    }
}
