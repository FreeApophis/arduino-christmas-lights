#pragma once

#include "Clearance.h"

// Clear the strip by 'eating' the pixels from the center
class EatFromCenter final : public Clearance {
  public:
    explicit EatFromCenter(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    int _remaining;
};