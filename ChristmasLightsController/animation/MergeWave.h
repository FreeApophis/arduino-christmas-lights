#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Fast merging of Waves
class MergeWave : public Animation {
  public:
    MergeWave(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    int l, r;
    byte index;
    byte len;
};