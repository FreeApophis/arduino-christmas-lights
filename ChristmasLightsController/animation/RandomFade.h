#pragma once

#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

// Random sparks fade out
class RandomFade final : public Animation {
  public:
    explicit RandomFade(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    BrightnessManipulation _brightnessManipulation;
};