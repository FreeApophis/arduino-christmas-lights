#pragma once

#include "Animation.h"
#include "../ColorSuperposition.h"
#include "../framework.h"

// Slow merging of two colors
class MergeOne : public ColorSuperposition, public Animation {
  public:
    MergeOne(AbstractLedStrip* strip, byte duration) :
        Animation(strip, duration, 8, 30)
    {
    }
    virtual void init();
    virtual void show();

  private:
    uint32_t cl, cr;
    int l, r;
};
