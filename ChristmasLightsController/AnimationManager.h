#pragma once

#include "SimulatedLedStrip.h"
#include "animation/Animation.h"
#include "clearance/Clearance.h"

class AnimationManager {
  public:
    AnimationManager(AbstractLedStrip* strip, Animation* animations[], byte numberOfAnimations, Clearance* clearances[], byte numberOfClearances);
    void Init(Animation* animation);
    void Show();
    uint16_t CurrentAnimationId() const;
    void StartAnimation(uint16_t animationId);

  private:
    void InitClear();
    bool IsClean();
    void SetStepSettings();
    Animation* NextAnimation();
    void AdvanceAnimation();
    void AdvanceClearance();

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
