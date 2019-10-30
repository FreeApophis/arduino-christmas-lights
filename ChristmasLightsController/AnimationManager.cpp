#include "AnimationManager.h"

#include "framework.h"

#include <cstdint>

void AnimationManager::init()
{
    if (!_animations[aIndex]->needsClear) {
        aIndex = Shuffle::next();
        //aIndex = 18;
        a = _animations[aIndex];

        uint32_t period = a->showTime;
        period = random(period, period * 3); // time in 10-seconds intervals
        period *= 10000;                     // Now time in ms
        next = millis() + period;
    }

    a = _animations[aIndex];
    uint16_t min_stp = a->minPeriod * 10;
    uint16_t max_stp = a->maxPeriod * 10;
    stp_period = random(min_stp, max_stp + 1);
    stp = 0;

    _strip->clear();
    a->needsClear = false;
    a->init();
    _strip->show();
    a->needsClear = false;
}

void AnimationManager::show()
{
    uint32_t ms = millis();
    if (!do_clear && (ms > next) && a->complete) { // The current animation is timed out
        if (isClean())
            init();
        else
            initClear();
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
        if (c->isComplete()) {
            do_clear = false;
            if (ms > next)
                a->needsClear = false; // It is too late to continue the animation
            init();
        } else
            c->show(); // Keep running clear session till it ends
    } else {
        if (a->needsClear)
            initClear();
        a->show();
    }
    _strip->show();
}

void AnimationManager::initClear()
{
    do_clear = true; // Start clearing sequence
    byte ni = random(num_clr);
    c = clearance[ni];
    c->init();
    stp = 0;
    clr_stp_period = random(3, 10) * 10;
}

bool AnimationManager::isClean()
{
    for (uint16_t i = 0; i < _strip->numPixels(); ++i)
        if (_strip->getPixelColor(i))
            return false;
    return true;
}