#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Random  colors toward each other
class Toward : public Animation {
  public:
    Toward(AbstractLedStrip* strip);

    void Init() override { w = random(256); }
    void Show() override;

  private:
    byte w;
};
