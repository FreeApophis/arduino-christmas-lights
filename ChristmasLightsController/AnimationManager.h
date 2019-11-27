#pragma once

#include "Shuffle.h"
#include "SimulatedLedStrip.h"
#include "Animation.h"
#include "Clearance.h"

class AnimationManager {
  public:
    AnimationManager(Animation* animations[], byte a_size, Clearance* c[], byte clr_size, AbstractLedStrip* strip);
    void Init();
    void Show();
    void Menu();
    void MenuL();

    void Increment();

  private:
    void InitClear();
    bool IsClean();

    Shuffle _shuffle;
    AbstractLedStrip* _strip{};
    Animation** _animations;
    Clearance** _clearances;
    byte num_clr;
    uint32_t stp = 0;
    uint16_t stp_period{};
    uint16_t clr_stp_period{};
    uint32_t next{};
    byte aIndex;
    Animation* a{};
    Clearance* c{};
    bool do_clear; // Whether cleaning the strip
};
