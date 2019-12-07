#pragma once

#include "animation/Animation.h"

class WarmWhiteShimmer final : public Animation {
  public:
    explicit WarmWhiteShimmer(AbstractLedStrip* strip);

    auto Init() -> void override;
    auto Show() -> void override;
};