#include "SingleWave.h"
#include "ColorManipulation.h"

SingleWave::SingleWave(AbstractLedStrip* strip):
    BrightnessManipulation(strip),
    Animation(strip, 12, 4, 20)
{
}

void SingleWave::Init()
{
    uint32_t c = ColorFromColorWheel(random(256));
    uint32_t r = c & 0xff;
    uint32_t g = (c >> 8) & 0xff;
    uint32_t b = (c >> 16) & 0xff;
    for (byte i = 1; i <= 4; ++i) {
        r >>= 1;
        g >>= 1;
        b >>= 1;
        uint32_t cc = b & 0xff;
        cc <<= 8;
        cc |= g & 0xff;
        cc <<= 8;
        cc |= r & 0xff;
        dot[i] = cc;
    }

    BrightnessManipulation::setColor(dot[3]);
    c &= 0x10101;
    int n = _strip->numPixels();
    for (int i = 0; i < n; ++i)
        _strip->setPixelColor(i, c);
    mode = 0;
    pos = random(n);
    remain = random(5, 15);
    stp = 0;
}

void SingleWave::Show()
{
    int n = _strip->numPixels();
    bool finish = true;
    switch (mode) {
        case 0: // Light up
            finish = BrightnessManipulation::changeAll(4);
            break;
        case 1: // move the soliton
            finish = false;
            if (stp <= 0) {
                incr = 1;
                if (pos > n / 2)
                    incr = -1;
                int m = n - pos - 2;
                if (incr < 0)
                    m = pos - 2;
                stp = random(5, m);
                --remain;
                if (remain <= 0) {
                    for (int i = 0; i < n; ++i)
                        _strip->setPixelColor(i, dot[3]);
                    finish = true;
                    break;
                }
            }
            pos += incr;
            for (int i = 0; i < n; ++i) {
                _strip->setPixelColor(i, dot[3]);
            }
            BrightnessManipulation::changeAll(random(9) - 4);
            for (int i = 3; i > 0; --i) {
                if ((pos - i) >= 0)
                    _strip->setPixelColor(pos - i, dot[i]);
            }
            for (int i = 0; i <= 3; ++i) {
                if ((pos + i) < n)
                    _strip->setPixelColor(pos + i, dot[i]);
            }
            stp--;
            break;
        case 2: // Fade out
        default:
            finish = BrightnessManipulation::changeAll(-4);
            break;
    }

    if (finish) { // The current color has been light fully
        ++mode;
        if (mode >= 3) {
            Init();
            _complete = true;
            return;
        }
    }
    _complete = false;
}