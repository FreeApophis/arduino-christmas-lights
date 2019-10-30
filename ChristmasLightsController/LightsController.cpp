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

void setup()
{
    randomize();

    strip.begin();
    strip.setBrightness(PixelBrightness);
    strip.show(); // Initialize all pixels to 'off'
    mgr.Init();
}

void loop()
{
    mgr.Show();
}