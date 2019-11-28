#include "ColorWave.h"

#include "ColorManipulation.h"

ColorWave::ColorWave(AbstractLedStrip* strip, byte duration) :
    BrightnessManipulation(strip),
    Animation(0x0104, strip, duration, 2, 8),
    _index(0),
    _isReady(false)
{
}

void ColorWave::Init()
{
    _index = 0;
    _isReady = false;

    _crawl.SetDirection(RandomDirection());
}

void ColorWave::Show()
{
    if (!_isReady) {
        _isReady = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            BrightnessManipulation::setColor(ColorFromColorWheel(((i * 256 / _strip->numPixels())) & 255));
            if (!BrightnessManipulation::change(i, 2))
                _isReady = false;
        }
        return;
    }

    _crawl.Step(_strip);
    if (_crawl.GetDirection() == CrawlDirection::Forward) {
        _strip->setPixelColor(0, ColorFromColorWheel(_index & 255));
    } else {
        _strip->setPixelColor(_strip->numPixels() - 1, ColorFromColorWheel(_index & 255));
    }
    ++_index;
}