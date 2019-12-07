#pragma once

#include "Animation.h"

class Fire final : public Animation {
  public:
    explicit Fire(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto SetPixelHeatColor(int index, byte temperature) const -> void;
    auto Burn(int cooling, int sparks) const -> void;
};
