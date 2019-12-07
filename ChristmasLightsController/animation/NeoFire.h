#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Neo fire animation by Robert Ulbricht
class NeoFire final : public Animation {
  public:
    explicit NeoFire(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    uint32_t _color;
    char _pause;
    const uint32_t _color1 = 80;
    const uint32_t _color2 = 25;
};
