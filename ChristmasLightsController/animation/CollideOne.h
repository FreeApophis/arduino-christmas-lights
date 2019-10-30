#pragma once

#include "Animation.h"
#include "../framework.h"

// Fast collide of two colors
class CollideOne : public Animation {
  public:
    CollideOne(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    uint32_t cl, cr;
    int l, r;
    bool boom;
};
