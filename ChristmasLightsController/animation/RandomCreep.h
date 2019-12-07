#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

#include "framework.h"

// creep the random sequence up or down
class RandomCreep final : public Animation {
  public:
    explicit RandomCreep(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    Crawl _crawl;
    byte _space; // space between the color dots
    int _changeDirection;
    byte _count;
};
