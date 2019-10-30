#pragma once

#include "Animation.h"
#include "../framework.h"

//---------------------------------------------- Fast merging of Waves ----------------------------------------------------
class MergeWave : public Animation {
  public:
    MergeWave(AbstractLedStrip* strip, byte duration) :
        Animation(strip, 2, 3, 20)
    {
    }
    virtual void init();
    virtual void show();

  private:
    int l, r;
    byte index;
    byte len;
};