#include "AnimationManager.h"

#include "manipulation/Clear.h"

#include "framework.h"

#include <cstdint>

AnimationManager::AnimationManager(AbstractLedStrip* strip, Animation* animations[], byte numberOfAnimations, Clearance* clearances[], byte numberOfClearances) :
    _strip(strip),
    _animations(animations),
    _numberOfAnimations(numberOfAnimations),
    _clearances(clearances),
    _numberOfClearances(numberOfClearances),
    _nextAnimation(nullptr),
    _nextStep(0),
    _stepPeriod(0),
    _clearStepPeriod(0),
    _currentAnimation(nullptr),
    _currentClearance(nullptr),
    _clearing(false)

{
}

auto AnimationManager::SetStepSettings() -> void
{
    const uint16_t stepMinPeriod = 10 * _currentAnimation->MinPeriod();
    const uint16_t stepMaxPeriod = 10 * _currentAnimation->MaxPeriod();

    // this is the minimal period for a singe animation step, higher values -> slower animation
    _stepPeriod = random(stepMinPeriod, stepMaxPeriod + 1);

    _nextStep = 0;
}

auto AnimationManager::NextAnimation() -> Animation*
{
    return _nextAnimation == nullptr
               ? _animations[0] // off animation (should not happen)
               : _nextAnimation;
}

auto AnimationManager::Init(Animation* animation) -> void
{
    _currentAnimation = animation;
    _nextAnimation = nullptr;

    SetStepSettings();

    Clear(_strip);
    _currentAnimation->SetNeedsClearance(false);
    _currentAnimation->Init();
    _strip->show();
    _currentAnimation->SetNeedsClearance(false);
}

auto AnimationManager::Show() -> void
{
    if (millis() < _nextStep) {
        delay(1);
    } else {
        if (_clearing) {
            AdvanceClearance();
        } else {
            AdvanceAnimation();
        }
    }
}

auto AnimationManager::CurrentAnimationId() const -> uint16_t
{
    return _currentAnimation->AnimationId();
}

auto AnimationManager::StartAnimation(uint16_t animationId) -> void
{
    for (byte index = 0; index < _numberOfAnimations; ++index) {
        if (_animations[index]->AnimationId() == animationId) {
            _nextAnimation = _animations[index];
            return;
        }
    }
}

auto AnimationManager::AdvanceAnimation() -> void
{
    // The current animation is timed out
    if (_nextAnimation != nullptr /* && _currentAnimation->IsComplete() */) {
        if (IsClean()) {
            Init(NextAnimation());
        } else {
            InitClear();
        }
    }

    const uint32_t ms = millis();
    _nextStep = ms + _stepPeriod;

    if (_currentAnimation->NeedsClearance()) {
        InitClear();
    }

    _currentAnimation->Show();

    _strip->show();
}

auto AnimationManager::AdvanceClearance() -> void
{
    const uint32_t ms = millis();
    _nextStep = ms + _clearStepPeriod;

    if (_currentClearance->IsComplete()) {
        _clearing = false;
        Init(NextAnimation());
    } else {
        _currentClearance->Show(); // Keep running clear session till it ends
    }
    _strip->show();
}

auto AnimationManager::InitClear() -> void
{
    _clearing = true;

    _currentClearance = _clearances[random(_numberOfClearances)];
    _currentClearance->Init();
    _nextStep = 0;
    _clearStepPeriod = random(3, 10) * 10;
}

auto AnimationManager::IsClean() const -> bool
{
    for (uint16_t index = 0; index < _strip->numPixels(); ++index) {
        if (_strip->getPixelColor(index)) {
            return false;
        }
    }
    return true;
}
