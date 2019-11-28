#include "RandomCreep.h"

#include "manipulation/ColorManipulation.h"

RandomCreep::RandomCreep(AbstractLedStrip* strip) :
    Animation(0x0112, strip, 6, 24),
    _space(0),
    _changeDirection(0)
{
}

void RandomCreep::Init()
{
    _space = random(2, 5);
    _changeDirection = random(100, 500);
    _count = 0;
}

void RandomCreep::Show()
{
    --_changeDirection;
    if (_changeDirection <= 0) {
        _crawl.ToggleDirection();
        Init();
    }

    _crawl.SetNextColor(0);
    ++_count;
    if (_count > _space) {
        _count = 0;
        _crawl.SetNextColor(ColorFromColorWheel(random(256)));
    }

    _crawl.Step(_strip);
}
