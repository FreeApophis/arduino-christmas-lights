#include "LightsController.h"

#include "AnimationManager.h"
#include "animation/Animation.h"
#include "animation/CenterRun.h"
#include "animation/CollEnd.h"
#include "animation/CollMdl.h"
#include "animation/CollideOne.h"
#include "animation/ColorSwing.h"
#include "animation/ColorWalk.h"
#include "animation/ColorWave.h"
#include "animation/ColorWipe.h"
#include "animation/EvenOdd.h"
#include "animation/FlashSeven.h"
#include "animation/Interference.h"
#include "animation/LightHouse.h"
#include "animation/LightUp.h"
#include "animation/MergeOne.h"
#include "animation/MergeWave.h"
#include "animation/NeoFire.h"
#include "animation/RainBlend.h"
#include "animation/RainCycle.h"
#include "animation/RainFull.h"
#include "animation/Rainbow.h"
#include "animation/RandomCreep.h"
#include "animation/RandomDrops.h"
#include "animation/RandomFade.h"
#include "animation/RandomFill.h"
#include "animation/ShineFlash.h"
#include "animation/ShineSeven.h"
#include "animation/SingleColorSwing.h"
#include "animation/SingleWave.h"
#include "animation/SolitonCreep.h"
#include "animation/Sparks.h"
#include "animation/Toward.h"
#include "animation/TowardRain.h"
#include "animation/WalkSeven.h"
#include "animation/Worms.h"
#include "clearance/ClearFade.h"
#include "clearance/ClearFromCenter.h"
#include "clearance/ClearHalf.h"
#include "clearance/ClearSide.h"
#include "clearance/Clearance.h"
#include "clearance/EatFromCenter.h"
#include "framework.h"

#ifdef ARDUINO
#else
#    include "SimulatedLedStrip.h"
#endif

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
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(NumberOfPixels, NEO_PIN, NEO_GRB + NEO_KHZ800);

SimulatedLedStrip strip(NumberOfPixels);

// Instantiate Animations
CenterRun centerRun(&strip, MinimalSequenceShowTime);
CollEnd collEnd(&strip, MinimalSequenceShowTime);
CollideOne collideOne(&strip);
CollMdl collMdl(&strip, MinimalSequenceShowTime);
ColorSwing colorSwing(&strip, MinimalSequenceShowTime);
ColorWalk colorWalk(&strip, MinimalSequenceShowTime);
ColorWave colorWave(&strip, MinimalSequenceShowTime);
ColorWipe colorWipe(&strip, MinimalSequenceShowTime);
EvenOdd evenOdd(&strip, MinimalSequenceShowTime);
FlashSeven flashSeven(&strip, MinimalSequenceShowTime);
Interference interference(&strip, MinimalSequenceShowTime);
LightHouse lightHouse(&strip);
LightUp lightUp(&strip, MinimalSequenceShowTime);
MergeOne mergeOn(&strip, MinimalSequenceShowTime);
MergeWave mergeWave(&strip, MinimalSequenceShowTime);
NeoFire neoFire(&strip, MinimalSequenceShowTime);
RainBlend rainBlend(&strip, MinimalSequenceShowTime);
Rainbow rainbow(&strip, MinimalSequenceShowTime);
RainCycle rainCycle(&strip, MinimalSequenceShowTime);
RainFull rainFull(&strip, MinimalSequenceShowTime);
RandomCreep randomCreep(&strip, MinimalSequenceShowTime);
RandomDrops randomDrops(&strip);
RandomFade randomFade(&strip, MinimalSequenceShowTime);
RandomFill randomFill(&strip, MinimalSequenceShowTime);
ShineFlash shineFlash(&strip, MinimalSequenceShowTime);
ShineSeven shineSeven(&strip, MinimalSequenceShowTime);
SingleColorSwing singleColorSwing(&strip);
SingleWave singleWave(&strip);
SolitonCreep solitonCreep(&strip, MinimalSequenceShowTime);
Sparks sparks(&strip, MinimalSequenceShowTime);
Toward toward(&strip, MinimalSequenceShowTime);
TowardRain towardRain(&strip, MinimalSequenceShowTime);
WalkSeven walkSeven(&strip, MinimalSequenceShowTime);
Worms worms(&strip);

// Instantiate Clearance Animations
ClearSide clrSide(&strip);
ClearFromCenter clearFromCenter(&strip);
ClearFade clearFade(&strip);
EatFromCenter eatFromCenter(&strip);
ClearHalf clearHalf(&strip);

Animation* animations[] = {
    //&centerRun,
    &collEnd,
    //&collideOne,
    //&collMdl,
    //&colorWalk,
    //&colorWave,
    //&colorWipe,
    //&evenOdd,
    //&flashSeven,
    //&interference,
    //&lightHouse,
    //&lightUp,
    //&mergeOn,
    //&mergeWave,
    //&neoFire,
    //&rainBlend,
    //&rainbow,
    //&rainCycle,
    //&rainFull,
    //&randomCreep,
    //&randomDrops,
    //&randomFade,
    //&randomFill,
    //&shineFlash,
    //&shineSeven,
    //&singleColorSwing,
    //&singleWave,
    //&solitonCreep,
    //&sparks,
    //&colorSwing,
    //&toward,
    //&towardRain,
    //&walkSeven,
    //&worms,
};

Clearance* clearances[] = {
    &clrSide,
    &clearFromCenter,
    &clearFade,
    &eatFromCenter,
    &clearHalf,
};

template<typename TElement, int NSize>
int arraySize(TElement (&array)[NSize])
{
    return NSize;
}

AnimationManager mgr(&strip, animations, arraySize(animations), clearances, arraySize(clearances));

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