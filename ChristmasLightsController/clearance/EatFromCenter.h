#pragma once

#include "Clearance.h"

// Clear the strip by 'eating' the pixels from the center
class EatFromCenter : public Clearance {
  public:
    EatFromCenter(AbstractLedStrip* strip);

    virtual void init();
    virtual void show();

  private:
    int remain;
};