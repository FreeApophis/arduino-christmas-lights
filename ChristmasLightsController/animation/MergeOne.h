#pragma once

#include "Animation.h"
#include "../framework.h"

// Slow merging of two colors
class MergeOne : public Animation {
  public:
    MergeOne(AbstractLedStrip* strip, byte duration) :
        Animation(strip, duration, 8, 30)
    {
    }
    virtual void Init();
    virtual void Show();

  private:
    uint32_t cl, cr;
    int l, r;
};
