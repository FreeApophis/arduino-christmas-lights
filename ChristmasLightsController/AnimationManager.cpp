#include "AnimationManager.h"

#include "framework.h"

#include <cstdint>

AnimationManager::AnimationManager(Animation* animations[], byte a_size, Clearance* clearances[], byte clr_size, AbstractLedStrip* strip) :
    Shuffle(a_size),
    _animations(animations),
    _clearances(clearances)
{
    num_clr = clr_size;
    stp = 0;
    do_clear = false;
    aIndex = 0;
}

void AnimationManager::Init()
{
    if (!_animations[aIndex]->NeedsClear()) {
        aIndex = Shuffle::next();
        //aIndex = 18;
        a = _animations[aIndex];

        uint32_t period = a->ShowTime();
        period = random(period, period * 3); // time in 10-seconds intervals
        period *= 10000;                     // Now time in ms
        next = millis() + period;
    }

    a = _animations[aIndex];
    uint16_t min_stp = a->MinPeriod() * 10;
    uint16_t max_stp = a->MaxPeriod() * 10;
    stp_period = random(min_stp, max_stp + 1);
    stp = 0;

    _strip->clear();
    a->SetNeedsClear(false);
    a->Init();
    _strip->show();
    a->SetNeedsClear(false);
}

void AnimationManager::Show()
{
    uint32_t ms = millis();
    if (!do_clear && (ms > next) && a->IsComplete()) { // The current animation is timed out
        if (IsClean())
            Init();
        else
            InitClear();
    }

    if (ms < stp) {
        delay(1);
        return;
    }
    if (do_clear)
        stp = ms + clr_stp_period;
    else
        stp = ms + stp_period;

    if (do_clear) {
        if (c->IsComplete()) {
            do_clear = false;
            if (ms > next)
                a->SetNeedsClear (false); // It is too late to continue the animation
            Init();
        } else
            c->Show(); // Keep running clear session till it ends
    } else {
        if (a->NeedsClear())
            InitClear();
        a->Show();
    }
    _strip->show();
}

void AnimationManager::Menu()
{
    stp_period--;
    if (stp_period < 1)
        stp_period = 1;
}

void AnimationManager::MenuL()
{
    InitClear();
}

void AnimationManager::Increment()
{
    stp_period++;
    if (stp_period > 20)
        stp_period = 20;
}

void AnimationManager::InitClear()
{
    do_clear = true; // Start clearing sequence
    byte ni = random(num_clr);
    c = _clearances[ni];
    c->Init();
    stp = 0;
    clr_stp_period = random(3, 10) * 10;
}

bool AnimationManager::IsClean()
{
    for (uint16_t i = 0; i < _strip->numPixels(); ++i)
        if (_strip->getPixelColor(i))
            return false;
    return true;
}