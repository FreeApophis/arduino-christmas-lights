#include "ClearFade.h"

ClearFade::ClearFade(AbstractLedStrip* strip) :
    Clearance(strip),
    _decrement(0)
{
}

auto ClearFade::Init() -> void
{
    _complete = false;
    _decrement = random(6, 16);
}

auto ClearFade::Show() -> void
{
    _complete = FadeAll(_decrement);
}
