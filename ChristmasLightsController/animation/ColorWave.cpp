#include "ColorWave.h"

#include "manipulation/ColorManipulation.h"

ColorWave::ColorWave(AbstractLedStrip* strip) :
    Animation(0x0104, strip, 2, 8),
    _brightnessManipulation(strip),
    _index(0),
    _isReady(false)
{
}

auto ColorWave::Init() -> void
{
    _index = 0;
    _isReady = false;

    _crawl.SetDirection(RandomDirection());
}

auto ColorWave::Show() -> void
{
    if (!_isReady) {
        _isReady = true;
        for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
            _brightnessManipulation.SetColor(ColorFromColorWheel(((i * 256 / _strip->numPixels())) & 255));
            if (!_brightnessManipulation.Change(i, 2))
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
