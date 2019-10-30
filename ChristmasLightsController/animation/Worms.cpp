#include "Worms.h"
#include "../Helper.h"


Worms::Worms(AbstractLedStrip* strip):
    BrightnessManipulation(strip),
    Animation(strip, 9, 10, 20)
{
}

void Worms::Init()
{
    active = 0;
    add();
}

void Worms::Show()
{
    int n = _strip->numPixels();

    // fade away
    BrightnessManipulation::changeAll(-32);

    // Move existing
    for (byte wi = 0; wi < active; ++wi) {
        int np = w[wi].pos - 1;
        if (w[wi].fwd)
            np += 2;
        if ((np < 0) || (np >= n)) {
            die(wi);
            --wi;
            continue;
        }
        uint32_t c = _strip->getPixelColor(np);
        if ((c != 0) && (random(10) == 0)) {
            die(wi);
            --wi;
            continue;
        } else {
            c = ColorSuperPosition(c, w[wi].color);
            w[wi].pos = np;
            _strip->setPixelColor(np, c);
        }
    }

    if (random(12) == 0)
        add();
}

void Worms::add()
{
    if (active >= 5)
        return;

    byte mode = random(3);
    int n = _strip->numPixels();
    switch (mode) {
        case 0: // Run from the start
            w[active].pos = 0;
            break;
        case 1: // Run from the end
            w[active].pos = n - 1;
            break;
        case 2: // Run from the random position
        default:
            w[active].pos = random(n);
            break;
    }
    w[active].color = ColorFromColorWheel(random(256));
    if (_strip->getPixelColor(w[active].pos) != 0)
        return;
    if (w[active].pos < n / 3) {
        w[active].fwd = true;
    } else if ((n - w[active].pos) < n / 3) {
        w[active].fwd = false;
    } else {
        w[active].fwd = random(2);
    }
    ++active;
}

void Worms::die(byte index)
{
    --active;
    w[index].color = w[active].color;
    w[index].pos = w[active].pos;
    w[index].fwd = w[active].fwd;
}