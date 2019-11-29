#include "ColorSwing.h"

#include "manipulation/ColorManipulation.h"

ColorSwing::ColorSwing(AbstractLedStrip* strip) :
    Animation(0x0102, strip, 3, 10),
    _length(0),
    _index(0),
    w(0),
    rnd(false)
{
}

void ColorSwing::Init()
{
    _length = 1;
    rnd = random(2);
    uint32_t c = ColorFromColorWheel(random(256));
    if (!rnd) { // Use rainbow colors from ColorFromColorWheel
        w = random(256);
        c = ColorFromColorWheel(w);
    }
    _strip->setPixelColor(0, c);
    _crawl.SetDirection(CrawlDirection::Forward);
    _crawl.SetNextColor(0);
    _index = _strip->numPixels() - _length - 1;
}

void ColorSwing::Show()
{
    _crawl.Step(_strip);
    --_index;

    if (_index < 0) {
        uint32_t c = ColorFromColorWheel(random(256));
        if (!rnd) {
            w += 4;
            c = ColorFromColorWheel(w);
        }
        if (_crawl.GetDirection() == CrawlDirection::Forward) {
            _strip->setPixelColor(_strip->numPixels() - _length - 1, c);
        } else {
            _strip->setPixelColor(_length, c);
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