#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

#include "framework.h"

// creep the random sequence up or down
class RandomCreep : public Animation {
  public:
    RandomCreep(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    Crawl _crawl;
    byte _space; // space between the color dots
    int _changeDirection;
    byte _count{};
};
