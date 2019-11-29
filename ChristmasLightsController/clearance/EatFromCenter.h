#pragma once

#include "Clearance.h"

// Clear the strip by 'eating' the pixels from the center
class EatFromCenter : public Clearance {
  public:
    EatFromCenter(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:
    int remain;
};