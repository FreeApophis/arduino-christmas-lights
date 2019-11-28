#pragma once

#include "animation/Animation.h"

#include "framework.h"

// Lights run from the center
class CenterRun : public Animation {
  public:
    CenterRun(AbstractLedStrip* strip, byte duration);

    // returns a value in the middle 1/8 of the strip
    int MiddleWithVariations() const;
    void SetParameters(int middle);

    void Init() override;
    bool IsFinished() const;
    void Show() override;

  private:
    uint32_t _color;
    int _middle;
    int _difference;
};
