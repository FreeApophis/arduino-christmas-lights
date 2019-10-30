#include "RandomCreep.h"

#include "../Helper.h"

RandomCreep::RandomCreep(AbstractLedStrip* strip, byte duration):
    Crawl(strip),
    Animation(strip, duration, 6, 24)
{
}

void RandomCreep::init()
{
    space = random(2, 5);
    change_direction = random(100, 500);
    cnt = 0;
}

void RandomCreep::show()
{
    --change_direction;
    if (change_direction <= 0) {
        Crawl::fwd = !Crawl::fwd;
        init();
    }

    next_color = 0;
    ++cnt;
    if (cnt > space) {
        cnt = 0;
        next_color = ColorFromColorWheel(random(256));
    }

    Crawl::step();
}
