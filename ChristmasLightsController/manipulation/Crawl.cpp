#include "Crawl.h"

Crawl::Crawl() :
    _nextColor(0),
    _crawlDirection(CrawlDirection::Forward)
{
}

void Crawl::SetDirection(CrawlDirection direction)
{
    _crawlDirection = direction;
}

void Crawl::ToggleDirection()
{
    _crawlDirection = _crawlDirection == CrawlDirection::Forward
                          ? CrawlDirection::Backward
                          : CrawlDirection::Forward;
}

CrawlDirection Crawl::GetDirection() const
{
    return _crawlDirection;
}

void Crawl::SetNextColor(uint32_t color)
{
    _nextColor = color;
}

uint32_t Crawl::NextColor() const
{
    return _nextColor;
}

void Crawl::Step(AbstractLedStrip* strip)
{
    if (_crawlDirection == CrawlDirection::Forward) {
        for (int i = strip->numPixels() - 1; i > 0; --i) {
            uint32_t c = strip->getPixelColor(i - 1);
            strip->setPixelColor(i, c);
        }
        strip->setPixelColor(0, _nextColor);
    } else { // creep backward
        const int last = strip->numPixels() - 1;
        for (int i = 0; i < last; ++i) {
            uint32_t c = strip->getPixelColor(i + 1);
            strip->setPixelColor(i, c);
        }
        strip->setPixelColor(last, _nextColor);
    }
}
