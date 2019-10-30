#pragma once

#include "Shuffle.h"
#include "SimulatedLedStrip.h"
#include "animation/Animation.h"
#include "clearance/Clearance.h"

class AnimationManager : public Shuffle {
  public:
    AnimationManager(Animation* animations[], byte a_size, Clearance* c[], byte clr_size, AbstractLedStrip* strip) :
        Shuffle(a_size),
        _animations(animations)
    {
        clearance = c;
        num_clr = clr_size;
        stp = 0;
        do_clear = false;
        aIndex = 0;
    }
    void init();
    void show();
    void menu()
    {
        stp_period--;
        if (stp_period < 1)
            stp_period = 1;
    }
    void menu_l() { initClear(); }
    void incr()
    {
        stp_period++;
        if (stp_period > 20)
            stp_period = 20;
    }

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
