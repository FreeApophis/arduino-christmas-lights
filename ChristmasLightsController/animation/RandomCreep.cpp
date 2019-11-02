#include "RandomCreep.h"

#include "ColorManipulation.h"

RandomCreep::RandomCreep(AbstractLedStrip* strip, byte duration):
    Crawl(strip),
    Animation(strip, duration, 6, 24)
{
}

void RandomCreep::Init()
{
    space = random(2, 5);
    change_direction = random(100, 500);
    cnt = 0;
}

void RandomCreep::Show()
{
    --change_direction;
    if (change_direction <= 0) {
        Crawl::fwd = !Crawl::fwd;
        Init();
    }

    next_color = 0;
    ++cnt;
    if (cnt > space) {
        cnt = 0;
        next_color = ColorFromColorWheel(random(256));
    }

    Crawl::step();
}
