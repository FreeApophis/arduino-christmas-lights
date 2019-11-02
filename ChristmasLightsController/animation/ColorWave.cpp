#include "ColorWave.h"

#include "ColorManipulation.h"

ColorWave::ColorWave(AbstractLedStrip* strip, byte duration) :
    Crawl(strip),
    BrightnessManipulation(strip),
    Animation(strip, duration, 2, 8),
    index(0),
    rdy(false)
{
}

void ColorWave::Init()
{
    index = 0;
    rdy = false;
    Crawl::fwd = random(2);
}

void ColorWave::Show()
{
    if (!rdy) {
        rdy = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            BrightnessManipulation::setColor(ColorFromColorWheel(((i * 256 / _strip->numPixels())) & 255));
            if (!BrightnessManipulation::change(i, 2))
                rdy = false;
        }
        return;
    }

    Crawl::step();
    if (Crawl::fwd)
        _strip->setPixelColor(0, ColorFromColorWheel(index & 255));
    else
        _strip->setPixelColor(_strip->numPixels() - 1, ColorFromColorWheel(index & 255));
    ++index;
}