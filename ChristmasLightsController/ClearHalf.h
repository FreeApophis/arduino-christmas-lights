#pragma once

#include "Clearance.h"

// Clear the strip by deviding it by 2
class ClearHalf : public Clearance {
  public:
    ClearHalf(AbstractLedStrip* strip) :
        Clearance(strip) {}

    void Init() override;
    void Show() override;

  private:
    int one_step{};
};