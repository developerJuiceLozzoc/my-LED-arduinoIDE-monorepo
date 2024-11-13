#ifndef MY_HELPER_H
#define MY_HELPER_H
#include "PlatformHelpers.h"

enum class WandBatonAnimationState {
    None, 
    SinColorPurple,
    RapidFlashSlowFade,
    PurpleGreenPingPong,
    PinkAndGoldSexy
};

void stateMachineForAnimationStateAndCurrentClicks(
	WandBatonAnimationState* state,
	uint32_t* clicks
);

void inputReceivedIncrementState(
	WandBatonAnimationState* state
);


void animatePGS();

void animatePGPP(long clicks);
void animateSCP(long clicks);
void animateRFSF(long clicks);



/*
If there are X colors, thatn we shall pass a color by reference and set it to the value locationed at colors[index], assumiong index < X
*/
void setPurpleColorForIndex(uint16_t * color, int index);
void setPinkColorForIndex(uint16_t * color, int index);
void setGoldColorForIndex(uint16_t * color, int index);
void setGreenColorForIndex(uint16_t * color, int index);



#endif
