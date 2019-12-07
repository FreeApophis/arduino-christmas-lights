#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Fast merging of Waves
class MergeWave final : public Animation {
  public:
    explicit MergeWave(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    int _left;
    int _right;
    byte _index;
    byte _length;
};