#include "ColorSwing.h"
#include "../Helper.h"

ColorSwing::ColorSwing(AbstractLedStrip* strip, byte duration):
    Crawl(strip),
    Animation(strip, 10, 3, 10)
{
}

void ColorSwing::Init()
{
    len = 1;
    rnd = random(2);
    uint32_t c = ColorFromColorWheel(random(256));
    if (!rnd) { // Use rainbow colors from ColorFromColorWheel
        w = random(256);
        c = ColorFromColorWheel(w);
    }
    _strip->setPixelColor(0, c);
    Crawl::fwd = true;
    Crawl::next_color = 0;
    index = _strip->numPixels() - len - 1;
}

void ColorSwing::Show()
{
    Crawl::step();
    --index;

    if (index < 0) {
        uint32_t c = ColorFromColorWheel(random(256));
        if (!rnd) {
            w += 4;
            c = ColorFromColorWheel(w);
        }
        if (Crawl::fwd)
            _strip->setPixelColor(_strip->numPixels() - len - 1, c);
        else
            _strip->setPixelColor(len, c);
        ++len;
        Crawl::fwd = !Crawl::fwd;
        index = _strip->numPixels() - len - 1;
        if (len >= int(_strip->numPixels())) {
            _needsClear = true; // Force the strip clerance
            _complete = true;
            return;
        }
    }
    _complete = false;
}