#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

// Lights run from the center
class ChristmasWave final : public Animation {
  public:
    explicit ChristmasWave(AbstractLedStrip* strip);
    auto Init() -> void override;
    auto Show() -> void override;

  private:
    auto Advance() -> void;
    auto IsQuadrant(byte quadrant) const -> bool;
    byte RedValue() const;
    byte GreenValue() const;
    uint32_t CurrentColor() const;
    Crawl _crawl;
    byte _currentStep;
};
