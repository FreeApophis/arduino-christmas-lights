#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

#include "framework.h"

// Solitons are creaping up or down
class SolitonCreep final : public Animation {
  public:
    explicit SolitonCreep(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto NewSoliton() -> void;

    Crawl _crawl;
    int _space;           // space between the solitons
    int _changeDirection; // the time to change direction
    uint32_t _dots[5];
    int _solitons;
    byte _wheelIndex;
};
