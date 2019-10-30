#pragma once

#include "Clearance.h"

// Clear the strip from the other side
class ClearSide : public Clearance {
  public:
    ClearSide(AbstractLedStrip* strip);
    virtual void init();
    virtual void show();

  private:
    uint32_t color;
    int index;
    bool fwd;
};