#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Lights run from the center
class CenterRun final : public Animation {
  public:
    explicit CenterRun(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    // returns a value in the middle 1/8 of the strip
    auto MiddleWithVariations() const -> int;
    auto SetParameters(int middle) -> void;
    auto IsFinished() const -> bool;

    uint32_t _color;
    int _middle;
    int _difference;
};
