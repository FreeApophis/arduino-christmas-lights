#pragma once

#include "animation/Animation.h"

class WarmWhiteShimmer : public Animation {
  public:
    WarmWhiteShimmer(AbstractLedStrip* strip);

    void Init() override;
    void Show() override;

  private:

};