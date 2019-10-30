#pragma once

#include "Animation.h"
#include "../framework.h"

// Fast collide of two colors
class CollideOne : public Animation {
  public:
    CollideOne(AbstractLedStrip* strip);
    virtual void init();
    virtual void show();

  private:
    uint32_t cl, cr;
    int l, r;
    bool boom;
};
