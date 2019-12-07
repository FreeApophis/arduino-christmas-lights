#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Rainbow colors toward each other
class TowardRain final : public Animation {
  public:
    explicit TowardRain(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    byte _wheelIndex;
};
