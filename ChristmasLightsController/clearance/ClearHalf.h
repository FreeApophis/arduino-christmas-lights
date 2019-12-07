#pragma once

#include "Clearance.h"

// Clear the strip by deviding it by 2
class ClearHalf : public Clearance {
  public:
    explicit ClearHalf(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    int _oneStep;
};