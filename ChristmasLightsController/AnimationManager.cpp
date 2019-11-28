#include "AnimationManager.h"

#include "framework.h"

#include <cstdint>

AnimationManager::AnimationManager(AbstractLedStrip* strip, Animation* animations[], byte numberOfAnimations, Clearance* clearances[], byte numberOfClearances) :
    _shuffle(numberOfAnimations),
    _strip(strip),
    _animations(animations),
    _numberOfAnimations(numberOfAnimations),
    _clearances(clearances),
    _numberOfClearances(numberOfClearances),
    _nextStep(0),
    _stepPeriod(0),
    _nextAnimation(0),
    _clearStepPeriod(0),
    _currentAnimation(nullptr),
    _currentClearance(nullptr),
    _clearing(false)

{
}

void AnimationManager::SetStepSettings()
{
    const uint16_t stepMinPeriod = 10 * _currentAnimation->MinPeriod();
    const uint16_t stepMaxPeriod = 10 * _currentAnimation->MaxPeriod();

    _stepPeriod = random(stepMinPeriod, stepMaxPeriod + 1);

    _nextStep = 0;
}

uint32_t AnimationManager::NextAnimationTime() const
{
    const int32_t showTime = _currentAnimation->ShowTime();
    const int32_t period = random(showTime, showTime * 3) * 1000;

    return millis() + period;
}

void AnimationManager::Init()
{
    _currentAnimation = _animations[_shuffle.next()];

    if (!_currentAnimation->NeedsClearance()) {
        _nextAnimation = NextAnimationTime();
    }

    SetStepSettings();

    _strip->clear();
    _currentAnimation->SetNeedsClearance(false);
    _currentAnimation->Init();
    _strip->show();
    _currentAnimation->SetNeedsClearance(false);
}

void AnimationManager::Show()
{
    if (_clearing) {
        AdvanceClearance();
    } else {
        AdvanceAnimation();
    }
}

uint16_t AnimationManager::CurrentAnimationId() const
{
    return _currentAnimation->AnimationId();
}

void AnimationManager::StartAnimation(uint16_t animationId)
{
    for (byte index = 0; index < _numberOfAnimations; ++index) {
        if (_animations[index]->AnimationId() == animationId) {
            _nextAnimation = index;
        }
    }
}

void AnimationManager::AdvanceAnimation()
{
    const uint32_t ms = millis();

    // The current animation is timed out
    if ((ms > _nextAnimation) && _currentAnimation->IsComplete()) {
        if (IsClean()) {
            Init();
        } else {
            InitClear();
        }
    }

    if (ms < _nextStep) {
        delay(1);
        return;
    }

    _nextStep = ms + _stepPeriod;

    if (_currentAnimation->NeedsClearance()) {
        InitClear();
    }

    _currentAnimation->Show();

    _strip->show();
}

void AnimationManager::AdvanceClearance()
{
    const uint32_t ms = millis();

    if (ms < _nextStep) {
        delay(1);
        return;
    }

    _nextStep = ms + _clearStepPeriod;

    if (_currentClearance->IsComplete()) {
        _clearing = false;
        if (ms > _nextAnimation) {
            _currentAnimation->SetNeedsClearance(false); // It is too late to continue the animation
        }
        Init();
    } else {
        _currentClearance->Show(); // Keep running clear session till it ends
    }
    _strip->show();
}

void AnimationManager::InitClear()
{
    _clearing = true;

    _currentClearance = _clearances[random(_numberOfClearances)];
    _currentClearance->Init();
    _nextStep = 0;
    _clearStepPeriod = random(3, 10) * 10;
}

bool AnimationManager::IsClean()
{
    for (uint16_t i = 0; i < _strip->numPixels(); ++i) {
        if (_strip->getPixelColor(i)) {
            return false;
        }
    }
    return true;
}