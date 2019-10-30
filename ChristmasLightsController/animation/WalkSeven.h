#pragma once


#include "Animation.h"
#include "../BrightnessManipulation.h"
#include "../framework.h"

//---------------------------------------------- Rapid walking by the different colors -----------------------------------
class WalkSeven : public BrightnessManipulation, public Animation {
  public:
    WalkSeven(AbstractLedStrip* strip, byte duration);
    virtual void Init();
    virtual void Show();

  private:
    char curs;
    byte w;
    bool fwd;
    int ch_dir;
    byte period;
};
