#include "PlatformHelpers.h"
#include "WandBatonUtilities.h"


inline int intFromState(WandBatonAnimationState state) {
    return static_cast<int>(state);
}

inline void setNextState(WandBatonAnimationState *state) {
  const int currentState = intFromState(*state);
  const int totalState = 5;
  PlatformAgnosticPixel black = PlatformAgnosticPixel(0, 0, 0);
  for(int i=0; i < CLUSTER_1_COUNT; i ++) {
		setPixel(black, i, ClusterNameEnum::largeCluster);
	}
	for(int i=0; i < CLUSTER_2_COUNT; i ++) {
		setPixel(black, i, ClusterNameEnum::smallCluster);
	}
  Show();                        
  *state = static_cast<WandBatonAnimationState>((currentState + 1) % totalState);
}


void setup() {
 setupLEDs();
}

WandBatonAnimationState currentState = WandBatonAnimationState::None;

void loop() {
  unsigned long currentMillis = millis(); 
  const int lengthOfAnimation = 8 * 1000; // 600 % millisoncs == 0 at 1 minute i think 4200 69
  PlatformAgnosticPixel pixel;


  if(
    (currentState == WandBatonAnimationState::None && currentMillis % 2000 == 0) ||
    (currentState != WandBatonAnimationState::None && currentMillis % lengthOfAnimation == 0)
   ) {
    setNextState(&currentState);
  }

  switch(currentState) {
    case WandBatonAnimationState::PinkAndGoldSexy:
      animatePGS();
      break;
    case WandBatonAnimationState::PurpleGreenPingPong:
      animatePGPP(currentMillis);
      break;
    case WandBatonAnimationState::RapidFlashSlowFade:
      animatePGPP(currentMillis);
      break;
    case WandBatonAnimationState::SinColorPurple:
      animateSCP(currentMillis);
      break;
      case WandBatonAnimationState::None:
      break;  
  }

}

/*
==========================
*/
