#pragma once

#include "Drop.h"
#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

// Random dropped color dot fading out from epicenter
class RandomDrops final : public Animation {
  public:
    explicit RandomDrops(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto Add() -> void;

    BrightnessManipulation _brightnessManipulation;
    Drop _drops[16];
    char _count;
};
