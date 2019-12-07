#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Random  colors toward each other
class Toward final : public Animation {
  public:
    explicit Toward(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    byte _wheelIndex;
};
