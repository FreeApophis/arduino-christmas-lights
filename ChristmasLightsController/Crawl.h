#pragma once

#include "AbstractLedStrip.h"

#include <cstdint>

// creep the sequence up or down, superclass
class Crawl {
  public:
    Crawl(AbstractLedStrip* strip);
    void step();

  protected:
    bool fwd; // direction to crawl: false - backward, true - formard
    uint32_t next_color{};
    AbstractLedStrip* _crawlStrip;
};