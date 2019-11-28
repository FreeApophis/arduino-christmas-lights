#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Rainbow colors toward each other
class TowardRain : public Animation {
  public:
    TowardRain(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    byte w{};
};
