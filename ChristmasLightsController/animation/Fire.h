#pragma once

#include "Animation.h"

class Fire : public Animation {
  public:
    Fire(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    void SetPixelHeatColor(int index, byte temperature);
    void Burn(int cooling, int sparks);
};
