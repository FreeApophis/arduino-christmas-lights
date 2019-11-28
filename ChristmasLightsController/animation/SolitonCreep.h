#pragma once

#include "animation/Animation.h"
#include "manipulation/Crawl.h"

#include "framework.h"

// Solitons are creaping up or down
class SolitonCreep : public Animation {
  public:
    SolitonCreep(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    Crawl _crawl;
    void newSoliton();
    int space{};            // space between the solitons
    int change_direction{}; // the time to change direction
    uint32_t dot[5]{};
    int sol{};
    byte w{};
};
