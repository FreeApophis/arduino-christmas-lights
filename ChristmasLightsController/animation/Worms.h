#pragma once

#include "Worm.h"
#include "animation/Animation.h"
#include "manipulation/BrightnessManipulation.h"

#include "framework.h"

// Several worms are moving randomly
class Worms final : public Animation {
  public:
    explicit Worms(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto Add() -> void;
    auto Die(byte index) -> void;

    BrightnessManipulation _brightnessManipulation;
    Worm _worms[5];
    byte _active;
};
