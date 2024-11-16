#include "WandBatonUtilities.h"
#include <EEPROM.h>


#define CLUSTER_1_PIN     9     
#define CLUSTER_2_PIN     5
#define COLOR_ORDER RGB
#define BRIGHTNESS  250     // Set the brightness (0-255)


inline int intFromState(WandBatonAnimationState state) {
    return static_cast<int>(state);
}


inline void setNextState(WandBatonAnimationState *state) {
  const int currentState = intFromState(*state);
  const int totalState = 5;
  fill_solid(ledCluster1, CLUSTER_1_COUNT, CRGB::Black);  
  fill_solid(ledCluster2, CLUSTER_2_COUNT, CRGB::Black);  
    FastLED.setBrightness(255);

  FastLED.show();                        
  *state = static_cast<WandBatonAnimationState>((currentState + 1) % totalState);
}

void setup() {
  FastLED.addLeds<WS2811, CLUSTER_1_PIN, COLOR_ORDER>(ledCluster1, CLUSTER_1_COUNT);
  FastLED.addLeds<WS2811, CLUSTER_2_PIN, COLOR_ORDER>(ledCluster2, CLUSTER_2_COUNT);
  FastLED.setBrightness(0);
}

WandBatonAnimationState currentState = WandBatonAnimationState::None;

void loop() {
  unsigned long currentMillis = millis(); 
  const int lengthOfAnimation = 8 * 1000; // 600 % millisoncs == 0 at 1 minute i think 4200 69
  CRGB pixel;


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