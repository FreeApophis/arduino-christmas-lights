#pragma once

#include "Animation.h"
#include "framework.h"


constexpr int num_inter = 3;
    //---------------------------------------------- Show interference from many sources ----------------------------------
class Interference : public Animation {

  public:
    Interference(AbstractLedStrip* strip, byte duration);

    void Init() override;
    void Show() override;

  private:
    void add();
    uint32_t clr(int p, byte source);
    int tm;               // Time the animation starts (in cycles)
    int pos[num_inter];   // The position os the source
    int start[num_inter]; // Time whan the source activated
    byte w[num_inter];    // Wheel Color index of the source
    byte active;          // The number of active sources
};
