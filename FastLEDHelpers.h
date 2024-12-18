#include "PlatformHelpers.h"


enum class WandBatonAnimationState {
    None, 
    SinColorPurple,
    RapidFlashSlowFade,
    PurpleGreenPingPong,
    PinkAndGoldSexy
};

enum class WindowAnimationState {
    None, 
    ColorBlink,
    CatAndMouse,
    SlowLoop
};

#ifndef SimpleStateMachineFlowBaton_H
#define SimpleStateMachineFlowBaton_H

/*
simple flow artist baton state machine, no gyro sensor*/
class SimpleStateMachineFlowBaton {
    public:
        SimpleStateMachineFlowBaton();
        void simpleFlowBatonLoop();
    private:
        WandBatonAnimationState currentState;
        void animatePGS();
        void animatePGPP(long clicks);
        void animateSCP(long clicks);
        void animateRFSF(long clicks);
        void setPurpleColorForIndex(PlatformAgnosticPixel * color, int index);
        void setPinkColorForIndex(PlatformAgnosticPixel * color, int index);
        void setGoldColorForIndex(PlatformAgnosticPixel * color, int index);
        void setGreenColorForIndex(PlatformAgnosticPixel * color, int index);

};
#endif

/* home window project

////////////////////
*/

#ifndef CHASESERVICE_H
#define CHASESERVICE_H
void homeWindowStripLoop();
class RabbitTurtleChaseService {
public:
    void updatePositions();
    RabbitTurtleChaseService();
    bool hasCaughtRabbit();
    void resetRace();

private:
    void updateTurtlePosition(unsigned long time);
    void updateRabbitPosition(unsigned long time);
    double turtleVelocity;
    double rabbitVelocity;
    int turtlePosition;
    double rabbitPosition;
    unsigned long rabbitAccelerationTimer;
    unsigned long startTime;
    void updateRabbitVelocity();
    unsigned long millisOffset;
    void printPhase();

};

#endif // CHASESERVICE_H


