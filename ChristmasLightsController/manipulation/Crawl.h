#pragma once

#include "AbstractLedStrip.h"
#include "CrawlDirection.h"

#include <cstdint>

// creep the sequence up or down
class Crawl final {
  public:
    Crawl();

    auto Step(AbstractLedStrip* strip) const -> void;

    auto SetDirection(CrawlDirection direction) -> void;
    auto ToggleDirection() -> void;

    auto GetDirection() const -> CrawlDirection;

    auto SetNextColor(uint32_t color) -> void;
    auto NextColor() const -> uint32_t;

  protected:
    // direction to crawl: false - backward, true - formard
    uint32_t _nextColor;
    CrawlDirection _crawlDirection;
};