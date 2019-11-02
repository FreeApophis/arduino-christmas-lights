#pragma once

#include "Crawl.h"
#include "animation/Animation.h"

#include "framework.h"

// creep the random sequence up or down
class RandomCreep : public Animation {
  public:
    RandomCreep(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    Crawl _crawl;
    byte _space; // space between the color dots
    int _changeDirection;
    byte _count{};
};
