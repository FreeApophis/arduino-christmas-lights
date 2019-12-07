#include "Crawl.h"

Crawl::Crawl() :
    _nextColor(0),
    _crawlDirection(CrawlDirection::Forward)
{
}

auto Crawl::SetDirection(CrawlDirection direction) -> void
{
    _crawlDirection = direction;
}

auto Crawl::ToggleDirection() -> void
{
    _crawlDirection = _crawlDirection == CrawlDirection::Forward
                          ? CrawlDirection::Backward
                          : CrawlDirection::Forward;
}

auto Crawl::GetDirection() const -> CrawlDirection
{
    return _crawlDirection;
}

auto Crawl::SetNextColor(uint32_t color) -> void
{
    _nextColor = color;
}

auto Crawl::NextColor() const -> uint32_t
{
    return _nextColor;
}

auto Crawl::Step(AbstractLedStrip* strip) const -> void
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
