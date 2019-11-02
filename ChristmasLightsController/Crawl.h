#pragma once

#include "AbstractLedStrip.h"
#include "CrawlDirection.h"

#include <cstdint>

// creep the sequence up or down, superclass
class Crawl {
  public:
    Crawl();

    void Step(AbstractLedStrip* strip);

    void SetDirection(CrawlDirection direction);
    void ToggleDirection();

    CrawlDirection GetDirection() const;

    void SetNextColor(uint32_t color);
    uint32_t NextColor() const;

  protected:
    // direction to crawl: false - backward, true - formard
    uint32_t _nextColor;
    CrawlDirection _crawlDirection;
};