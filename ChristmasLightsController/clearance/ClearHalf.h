#pragma once

#include "Clearance.h"

// Clear the strip by deviding it by 2
class ClearHalf : public Clearance {
  public:
    ClearHalf(AbstractLedStrip* strip) :
        Clearance(strip) {}
    virtual void init();
    virtual void show();

  private:
    int one_step;
};