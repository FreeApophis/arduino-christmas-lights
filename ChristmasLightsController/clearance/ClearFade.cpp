#include "ClearFade.h"

ClearFade::ClearFade(AbstractLedStrip* strip) :
    Clearance(strip)
{
}

void ClearFade::Init()
{
    _complete = false;
    decrement = random(4, 16);
}

void ClearFade::Show()
{
    _complete = Clearance::FadeAll(decrement);
}
