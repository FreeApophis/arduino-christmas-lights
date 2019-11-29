#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Rainbow colors blend
class RainBlend : public Animation {
  public:
    RainBlend(AbstractLedStrip* strip);

    void Init() override { _index = 0; }
    void Show() override;

  private:
    int _index;
};
