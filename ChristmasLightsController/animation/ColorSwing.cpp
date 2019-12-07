#include "ColorSwing.h"

#include "manipulation/ColorManipulation.h"

ColorSwing::ColorSwing(AbstractLedStrip* strip) :
    Animation(0x0102, strip, 3, 10),
    _length(0),
    _index(0),
    _wheelIndex(0),
    _random(false)
{
}

auto ColorSwing::Init() -> void
{
    _length = 1;
    _random = random(2);
    auto color = ColorFromColorWheel(random(256));
    if (!_random) { // Use rainbow colors from ColorFromColorWheel
        _wheelIndex = random(256);
        color = ColorFromColorWheel(_wheelIndex);
    }
    _strip->setPixelColor(0, color);
    _crawl.SetDirection(CrawlDirection::Forward);
    _crawl.SetNextColor(0);
    _index = _strip->numPixels() - _length - 1;
}

auto ColorSwing::Show() -> void
{
    _crawl.Step(_strip);
    --_index;

    if (_index < 0) {
        auto color = ColorFromColorWheel(random(256));
        if (!_random) {
            _wheelIndex += 4;
            color = ColorFromColorWheel(_wheelIndex);
        }
        if (_crawl.GetDirection() == CrawlDirection::Forward) {
            _strip->setPixelColor(_strip->numPixels() - _length - 1, color);
        } else {
            _strip->setPixelColor(_length, color);
        }
        ++_length;
        _crawl.ToggleDirection();
        _index = _strip->numPixels() - _length - 1;
        if (_length >= int(_strip->numPixels())) {
            _needsClearance = true; // Force the strip clerance
            _complete = true;
            return;
        }
    }
    _complete = false;
}
