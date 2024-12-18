#include "FastLEDHelpers.h"

void setup() {
//  Serial.begin(9600);
 setupLEDs();

}

void loop() {
    // Uncomment to implment home window
    homeWindowStripLoop();

    // static SimpleStateMachineFlowBaton animator = SimpleStateMachineFlowBaton();
    // animator.simpleFlowBatonLoop();

}