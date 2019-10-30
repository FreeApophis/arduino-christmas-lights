#pragma once

#include "Animation.h"

#include "../Crawl.h"
#include "../framework.h"

// creep the random sequence up or down
class RandomCreep : public Crawl, public Animation {
  public:
    RandomCreep(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    byte space; // space between the color dots
    int change_direction;
    byte cnt;
};
