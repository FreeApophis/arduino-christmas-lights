#include "ClearFade.h"

ClearFade::ClearFade(AbstractLedStrip* strip) :
    Clearance(strip)
{
}

void ClearFade::init()
{
    complete = false;
    decrement = random(4, 16);
}

void ClearFade::show()
{
    complete = Clearance::fadeAll(decrement);
}
