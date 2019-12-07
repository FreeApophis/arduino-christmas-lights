#include "SingleWave.h"

#include "manipulation/ColorManipulation.h"

SingleWave::SingleWave(AbstractLedStrip* strip) :
    Animation(0x0119, strip, 4, 20),
    _brightnessManipulation(strip),
    _dots{},
    _position(0),
    _stop(0),
    _remain(0),
    _increment(0),
    _mode(0)
{
}

auto SingleWave::Init() -> void
{
    auto color = ColorFromColorWheel(random(256));
    uint32_t red = ExtractRed(color);
    uint32_t green = ExtractGreen(color);
    uint32_t blue = ExtractBlue(color);
    for (byte index = 1; index <= 4; ++index) {
        red >>= 1;
        green >>= 1;
        blue >>= 1;
        auto cc = blue & 0xff;
        cc <<= 8;
        cc |= green & 0xff;
        cc <<= 8;
        cc |= red & 0xff;
        _dots[index] = cc;
    }

    _brightnessManipulation.SetColor(_dots[3]);
    color &= 0x10101;
    const int pixelCount = _strip->numPixels();
    for (auto i = 0; i < pixelCount; ++i) {
        _strip->setPixelColor(i, color);
    }
    _mode = 0;
    _position = random(pixelCount);
    _remain = random(5, 15);
    _stop = 0;
}

auto SingleWave::Show() -> void
{
    const int pixelCount = _strip->numPixels();
    bool finish;
    switch (_mode) {
        case 0: // Light up
            finish = _brightnessManipulation.ChangeAll(4);
            break;
        case 1: // move the soliton
            finish = false;
            if (_stop <= 0) {
                _increment = 1;
                if (_position > pixelCount / 2) {
                    _increment = -1;
                }
                int m = pixelCount - _position - 2;
                if (_increment < 0) {
                    m = _position - 2;
                }
                _stop = random(5, m);
                --_remain;
                if (_remain <= 0) {
                    for (int i = 0; i < pixelCount; ++i) {
                        _strip->setPixelColor(i, _dots[3]);
                    }
                    finish = true;
                    break;
                }
            }
            _position += _increment;
            for (auto index = 0; index < pixelCount; ++index) {
                _strip->setPixelColor(index, _dots[3]);
            }
            _brightnessManipulation.ChangeAll(random(9) - 4);
            for (auto index = 3; index > 0; --index) {
                if ((_position - index) >= 0) {
                    _strip->setPixelColor(_position - index, _dots[index]);
                }
            }
            for (auto index = 0; index <= 3; ++index) {
                if ((_position + index) < pixelCount) {
                    _strip->setPixelColor(_position + index, _dots[index]);
                }
            }
            _stop--;
            break;
        case 2: // Fade out
        default:
            finish = _brightnessManipulation.ChangeAll(-4);
            break;
    }

    if (finish) { // The current color has been light fully
        ++_mode;
        if (_mode >= 3) {
            Init();
            _complete = true;
            return;
        }
    }
    _complete = false;
}
