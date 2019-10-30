#pragma once

#include "Animation.h"
#include "../framework.h"

// Slow merging of two colors
class MergeOne : public Animation {
  public:
    MergeOne(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    uint32_t cl, cr;
    int l, r;
};
