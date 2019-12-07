#pragma once

#include "SimulatedLedStrip.h"
#include "animation/Animation.h"
#include "clearance/Clearance.h"

class AnimationManager {
  public:
    AnimationManager(AbstractLedStrip* strip, Animation* animations[], byte numberOfAnimations, Clearance* clearances[], byte numberOfClearances);
    auto Init(Animation* animation) -> void;
    auto Show() -> void;
    auto CurrentAnimationId() const -> uint16_t;
    auto StartAnimation(uint16_t animationId) -> void;

  private:
    auto InitClear() -> void;
    auto IsClean() const -> bool;
    auto SetStepSettings() -> void;
    auto NextAnimation() -> Animation*;
    auto AdvanceAnimation() -> void;
    auto AdvanceClearance() -> void;

    AbstractLedStrip* _strip;

    Animation** _animations;
    byte _numberOfAnimations;

    Clearance** _clearances;
    byte _numberOfClearances;

    Animation* _nextAnimation;

    uint32_t _nextStep;
    uint16_t _stepPeriod;
    uint16_t _clearStepPeriod;
    Animation* _currentAnimation;
    Clearance* _currentClearance;
    bool _clearing;
};
