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

void Crawl::Step(AbstractLedStrip* strip) const
{
    if (_crawlDirection == CrawlDirection::Forward) {
        for (auto i = strip->numPixels() - 1; i > 0; --i) {
            const auto color = strip->getPixelColor(i - 1);
            strip->setPixelColor(i, color);
        }
        strip->setPixelColor(0, _nextColor);
    } else { // creep backward
        const auto last = strip->numPixels() - 1;
        for (auto i = 0; i < last; ++i) {
            const auto color = strip->getPixelColor(i + 1);
            strip->setPixelColor(i, color);
        }
        strip->setPixelColor(last, _nextColor);
    }
}
