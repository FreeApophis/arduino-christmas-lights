#pragma once

#include "Clearance.h"

// Clear the strip from the ether side
class Brighten final : public Clearance {
  public:
    explicit Brighten(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;

  private:
    int _step;
};
