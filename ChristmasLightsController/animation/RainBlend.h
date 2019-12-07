#pragma once

#include "animation/Animation.h"

// Rainbow colors blend
class RainBlend final : public Animation {
  public:
    explicit RainBlend(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    int _index;
};
