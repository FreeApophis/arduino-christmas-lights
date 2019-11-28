#pragma once

#include "Shuffle.h"
#include "SimulatedLedStrip.h"
#include "animation/Animation.h"
#include "clearance/Clearance.h"

class AnimationManager {
  public:
    AnimationManager(AbstractLedStrip* strip, Animation* animations[], byte numberOfAnimations, Clearance* clearances[], byte numberOfClearances);
    void Init();
    void Show();
    uint16_t CurrentAnimationId() const;
    void StartAnimation(uint16_t animationId);

  private:
    void InitClear();
    bool IsClean();
    void SetStepSettings();
    uint32_t NextAnimationTime() const;
    void AdvanceAnimation();
    void AdvanceClearance();

    Shuffle _shuffle;
    AbstractLedStrip* _strip;
    Animation** _animations;
    byte _numberOfAnimations;
    Clearance** _clearances;
    byte _numberOfClearances;
    uint32_t _nextStep;
    uint16_t _stepPeriod;
    uint32_t _nextAnimation;
    uint16_t _clearStepPeriod;
    Animation* _currentAnimation;
    Clearance* _currentClearance;
    bool _clearing;
};
