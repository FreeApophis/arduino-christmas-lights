#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Slow merging of two colors
class MergeOne : public Animation {
  public:
    MergeOne(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    uint32_t cl;
    uint32_t cr;
    int l;
    int r;
};
