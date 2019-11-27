#include "LightsController.h"

#ifdef _MSC_VER

#include "AnimationManager.h"
#include "Animation.h"
#include "CenterRun.h"
#include "CollEnd.h"
#include "CollMdl.h"
#include "CollideOne.h"
#include "ColorSwing.h"
#include "ColorWalk.h"
#include "ColorWave.h"
#include "ColorWipe.h"
#include "EvenOdd.h"
#include "FlashSeven.h"
#include "Interference.h"
#include "LightHouse.h"
#include "LightUp.h"
#include "MergeOne.h"
#include "MergeWave.h"
#include "NeoFire.h"
#include "RainBlend.h"
#include "RainCycle.h"
#include "RainFull.h"
#include "Rainbow.h"
#include "RandomCreep.h"
#include "RandomDrops.h"
#include "RandomFade.h"
#include "RandomFill.h"
#include "ShineFlash.h"
#include "ShineSeven.h"
#include "SingleColorSwing.h"
#include "SingleWave.h"
#include "SolitonCreep.h"
#include "Sparks.h"
#include "StaticColor.h"
#include "Toward.h"
#include "TowardRain.h"
#include "WalkSeven.h"
#include "Worms.h"
#include "ClearFade.h"
#include "ClearFromCenter.h"
#include "ClearHalf.h"
#include "ClearSide.h"
#include "Clearance.h"
#include "EatFromCenter.h"
#include "framework.h"

#include "SimulatedLedStrip.h"

const byte PixelBrightness = 100;

// Pin of Neopixel Strip
//const byte NEO_PIN = 6;

// Length of Neopixel Strip
const byte NumberOfPixels = 100;

// seconds
const byte MinimalSequenceShowTime = 30;
//
//// Parameter 1 = number of pixels in strip
//// Parameter 2 = Arduino pin number (most are valid)
//// Parameter 3 = pixel type flags, add together as needed:
////   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
////   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
////   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
////   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//

#ifdef _MSC_VER
SimulatedLedStrip strip(NumberOfPixels);
#else
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NumberOfPixels, NEO_PIN, NEO_GRB + NEO_KHZ800);
#endif

// Instantiate Animations
ColorWipe colorWipe(&strip, MinimalSequenceShowTime);
ColorWalk colorWalk(&strip, MinimalSequenceShowTime);
RandomCreep randomCreep(&strip, MinimalSequenceShowTime);
Rainbow rainbow(&strip, MinimalSequenceShowTime);
RainCycle rainCycle(&strip, MinimalSequenceShowTime);
RainFull rainFull(&strip, MinimalSequenceShowTime);
ColorWave colorWave(&strip, MinimalSequenceShowTime);
LightUp lightUp(&strip, MinimalSequenceShowTime);
Sparks sparks(&strip, MinimalSequenceShowTime);
RandomFade randomFade(&strip, MinimalSequenceShowTime);
CenterRun centerRun(&strip, MinimalSequenceShowTime);
ShineSeven shineSeven(&strip, MinimalSequenceShowTime);
WalkSeven walkSeven(&strip, MinimalSequenceShowTime);
FlashSeven flashSeven(&strip, MinimalSequenceShowTime);
ShineFlash shineFlash(&strip, MinimalSequenceShowTime);
MergeOne mergeOn(&strip, MinimalSequenceShowTime);
MergeWave mergeWave(&strip, MinimalSequenceShowTime);
CollideOne collideOne(&strip);
NeoFire neoFire(&strip, MinimalSequenceShowTime);
EvenOdd evenOdd(&strip, MinimalSequenceShowTime);
CollMdl collMdl(&strip, MinimalSequenceShowTime);
CollEnd collEnd(&strip, MinimalSequenceShowTime);
RainBlend rainBlend(&strip, MinimalSequenceShowTime);
ColorSwing swing(&strip, MinimalSequenceShowTime);
SingleColorSwing singleColorSwing(&strip);
RandomFill randomFill(&strip, MinimalSequenceShowTime);
SingleWave singleWave(&strip);
Worms worms(&strip);
Interference interfer(&strip, MinimalSequenceShowTime);
Toward toward(&strip, MinimalSequenceShowTime);
TowardRain towardRain(&strip, MinimalSequenceShowTime);
LightHouse lightHouse(&strip);
RandomDrops randomDrops(&strip);
SolitonCreep solitonCreep(&strip, MinimalSequenceShowTime);
StaticColor staticColor(&strip, MinimalSequenceShowTime);

// Instantiate Clearance Animations
ClearSide clrSide(&strip);
ClearFromCenter clearFromCenter(&strip);
ClearFade clearFade(&strip);
EatFromCenter eatFromCenter(&strip);
ClearHalf clearHalf(&strip);

Animation* animations[] = {
    &colorWipe,
    &colorWalk,
    &randomCreep,
    &rainbow,
    &rainCycle,
    &rainFull,
    &colorWave,
    &lightUp,
    &sparks,
    &randomFade,
    &centerRun,
    &shineSeven,
    &walkSeven,
    &flashSeven,
    &shineFlash,
    &mergeOn,
    &mergeWave,
    &collideOne,
    &neoFire,
    &evenOdd,
    &collMdl,
    &collEnd,
    &rainBlend,
    &swing,
    &singleColorSwing,
    &randomFill,
    &singleWave,
    &worms,
    &interfer,
    &toward,
    &towardRain,
    &lightHouse,
    &randomDrops,
    &solitonCreep,
    &staticColor,
};

Clearance* clearances[] = {
    &clrSide,
    &clearFromCenter,
    &clearFade,
    &eatFromCenter,
    &clearHalf,
};
const byte num_anim = sizeof(animations) / sizeof(Animation*);
const byte num_clr = sizeof(clearances) / sizeof(Clearance*);

AnimationManager mgr(animations, num_anim, clearances, num_clr, &strip);

void randomize()
{
    //Serial.begin(9600);

    //uint32_t rnd = 0;
    //for (byte i = A0; i < A4; ++i) {
    //    pinMode(i, INPUT);
    //    rnd <<= 6;
    //    rnd += analogRead(i);
    //}
    //randomSeed(rnd);
}

uint16_t setup()
{
    randomize();

    strip.begin();
    strip.setBrightness(PixelBrightness);
    strip.show(); // Initialize all pixels to 'off'
    mgr.Init();

    return strip.numPixels();
}

uint32_t* loop()
{
    mgr.Show();

    incrementMillis();
    return strip.CurrentPixels().data();
}
#endif
