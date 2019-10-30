#pragma once

#include "Animation.h"
#include "../Crawl.h"
#include "../framework.h"

// Solitons are creaping up or down
class SolitonCreep : public Crawl, public Animation {
  public:
    SolitonCreep(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void newSoliton();
    int space{};            // space between the solitons
    int change_direction{}; // the time to change direction
    uint32_t dot[5]{};
    int sol{};
    byte w{};
};
