#pragma once


#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../ColorSuperposition.h"
#include "../framework.h"

//---------------------------------------------- Rapid walking by the different colors -----------------------------------
class WalkSeven : public BrightnessManipulation, public ColorSuperposition, public Animation {
  public:
    WalkSeven(AbstractLedStrip* strip, byte duration);
    virtual void init();
    virtual void show();

  private:
    char curs;
    byte w;
    bool fwd;
    int ch_dir;
    byte period;
};
