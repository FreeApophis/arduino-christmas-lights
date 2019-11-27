#pragma once

#include "AbstractLedStrip.h"

#ifdef _MSC_VER
#    include <cstdint>
#endif
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