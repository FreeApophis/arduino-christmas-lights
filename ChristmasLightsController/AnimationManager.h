#pragma once

#include "Shuffle.h"
#include "SimulatedLedStrip.h"
#include "animation/Animation.h"
#include "clearance/Clearance.h"

class AnimationManager : public Shuffle {
  public:
    AnimationManager(Animation* animations[], byte a_size, Clearance* c[], byte clr_size, AbstractLedStrip* strip);
    void init();
    void show();
    void menu();
    void menu_l();

    void incr();

  private:
    SimulatedLedStrip* _strip;
    void initClear();
    bool isClean();
    Animation** _animations;
    Clearance** clearance;
    byte num_clr;
    uint32_t stp = 0;
    uint16_t stp_period;
    uint16_t clr_stp_period;
    uint32_t next;
    byte aIndex;
    Animation* a;
    Clearance* c;
    bool do_clear; // Whether cleaning the strip
};
