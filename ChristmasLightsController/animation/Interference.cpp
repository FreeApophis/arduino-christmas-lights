#include "Interference.h"

#include "../Helper.h"
#include <cstdlib>

Interference::Interference(AbstractLedStrip* strip, byte duration):
    Animation(strip, 6, 6, 10),
    tm(0),
    pos{},
    start{},
    w{},
    active(0)
{
}

void Interference::Init()
{
    active = 0;
    tm = 0;
    add();
}

void Interference::Show()
{
    const int n = _strip->numPixels();

    for (int i = 0; i < n; ++i) {
        uint32_t c = 0;
        for (byte j = 0; j < active; ++j) {
            const uint32_t c1 = clr(i, j);
            c = ColorSuperPosition(c, c1);
        }
        _strip->setPixelColor(i, c);
    }
    ++tm;
    if (tm % 64 == 0) {
        for (byte i = 0; i < active; ++i)
            w[i] += 4;
    }

    if (!random(20))
        add();
}

void Interference::add()
{
    if (active >= num_inter)
        return;
    pos[active] = random(_strip->numPixels());
    w[active] = random(256);
    start[active] = tm;
    active++;
}

uint32_t Interference::clr(int p, byte source)
{
    uint32_t c = 0;
    const int s_pos = pos[source];
    int e = tm - start[source];
    e -= abs(p - s_pos);
    if (e < 0)
        return c; // The wave is not here yet
    e %= 64;      // The wave period
    byte elm;
    if (e < 32) // Half way
        elm = (31 - e) << 3;
    else
        elm = (e - 64) << 3;

    const uint32_t color = ColorFromColorWheel(w[source]);
    for (byte i = 0; i < 3; ++i) {
        int max_c = (color >> (8 * i)) & 0xff;
        max_c -= elm;
        if (max_c < 0)
            max_c = 0;
        uint32_t nc = max_c;
        nc <<= 8 * i;
        c |= nc;
    }
    return c;
}