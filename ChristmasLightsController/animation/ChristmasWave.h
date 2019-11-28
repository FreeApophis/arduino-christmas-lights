#pragma once

#include "animation/Animation.h"

#include "manipulation/Crawl.h"

// Lights run from the center
class ChristmasWave final : public Animation {
  public:
    ChristmasWave(AbstractLedStrip* strip, byte duration);
    void Init() override;
    void Show() override;

  private:
    void Advance();
    bool IsQuadrant(byte quadrant) const;
    byte RedValue() const;
    byte GreenValue() const;
    uint32_t CurrentColor() const;
    Crawl _crawl;
    byte _step;
};
