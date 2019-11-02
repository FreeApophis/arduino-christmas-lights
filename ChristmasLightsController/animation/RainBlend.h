#pragma once

#include "animation/Animation.h"
#include "framework.h"

// Rainbow colors blend
class RainBlend : public Animation {
  public:
    RainBlend(AbstractLedStrip* strip, byte duration);

    void Init() override { index = 0; }
    void Show() override;

  private:
    int index;
};
