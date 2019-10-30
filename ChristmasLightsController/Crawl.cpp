#include "Crawl.h"

Crawl::Crawl(AbstractLedStrip* strip) :
    fwd(true),
    _crawlStrip(strip)
{
}

void Crawl::step()
{
    if (fwd) { // creep forward
        for (int i = _crawlStrip->numPixels() - 1; i > 0; --i) {
            uint32_t c = _crawlStrip->getPixelColor(i - 1);
            _crawlStrip->setPixelColor(i, c);
        }
        _crawlStrip->setPixelColor(0, next_color);
    } else { // creep backward
        int last = _crawlStrip->numPixels() - 1;
        for (int i = 0; i < last; ++i) {
            uint32_t c = _crawlStrip->getPixelColor(i + 1);
            _crawlStrip->setPixelColor(i, c);
        }
        _crawlStrip->setPixelColor(last, next_color);
    }
}
