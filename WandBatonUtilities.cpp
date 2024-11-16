#include "WandBatonUtilities.h"
#if defined(PimpMyRide) || defined(FlowArdinoMini)

#endif



void stateMachineForAnimationStateAndCurrentClicks(
	WandBatonAnimationState* state,
	uint32_t* clicks
) {

}

void inputReceivedIncrementState(
	WandBatonAnimationState* state
) {
	
}

void animatePGS() {
	// Define deep pink and gold color values
	PlatformAgnosticPixel deepPink = PlatformAgnosticPixel(255, 20, 147);
	PlatformAgnosticPixel gold = PlatformAgnosticPixel(255, 215, 0);
	setPixel(deepPink, 0, ClusterNameEnum::smallCluster);
	setPixel(gold, 0, ClusterNameEnum::smallCluster);
	setPixel(deepPink, 0, ClusterNameEnum::smallCluster);

	setPixel(deepPink, 0, ClusterNameEnum::largeCluster);
	setPixel(gold, 1, ClusterNameEnum::largeCluster);
	setPixel(deepPink, 2, ClusterNameEnum::largeCluster);
	setPixel(gold, 3, ClusterNameEnum::largeCluster);
	setPixel(deepPink, 4, ClusterNameEnum::largeCluster);
	setPixel(deepPink, 5, ClusterNameEnum::largeCluster);
	setPixel(gold, 6, ClusterNameEnum::largeCluster);
	Show();
}

void animatePGPP(long clicks) {
	PlatformAgnosticPixel poisonGreen = PlatformAgnosticPixel(64, 255, 0);
	PlatformAgnosticPixel deepPurple = PlatformAgnosticPixel(75, 0, 130);

	// Calculate the interpolation factor with a sine wave, mapping it to 0-1
	float interpolationFactor = (sin(millis() * 0.003) + 1) / 2.0;

	// Interpolate between Poison Green and Deep Purple
	PlatformAgnosticPixel blendedColor = myBlend(poisonGreen, deepPurple, interpolationFactor * 255);

	// Set LED clusters to the interpolated color
	for(int i=0; i < CLUSTER_1_COUNT; i ++) {
		setPixel(blendedColor, i, ClusterNameEnum::largeCluster);
	}
	for(int i=0; i < CLUSTER_2_COUNT; i ++) {
		setPixel(blendedColor, i, ClusterNameEnum::smallCluster);
	}
	uint8_t brightness = (sin(millis() * 0.001) + 1) * 127.5;
	setBrightness(brightness);
	Show();
}

void animateSCP(long clicks) {
	PlatformAgnosticPixel purple1 = PlatformAgnosticPixel(128, 0, 128);
	PlatformAgnosticPixel purple2 = PlatformAgnosticPixel(75, 0, 130);
	uint8_t brightness = (sin(clicks * 0.003) + 1) * 127.5;

	for(int i=0; i < CLUSTER_1_COUNT; i ++) {
		setPixel(purple1, i, ClusterNameEnum::largeCluster);
	}
	for(int i=0; i < CLUSTER_2_COUNT; i ++) {
		setPixel(purple2, i, ClusterNameEnum::smallCluster);
	}
	setBrightness(brightness);
	Show();
}

void animateRFSF(long clicks) {

}

void setPurpleColorForIndex(PlatformAgnosticPixel * color, int index){
	PlatformAgnosticPixel colors[] = {
		// Purple shades
		PlatformAgnosticPixel(128, 0, 128),   // Purple
		PlatformAgnosticPixel(147, 112, 219), // MediumPurple
		PlatformAgnosticPixel(138, 43, 226),  // BlueViolet
	};
	*color = colors[index];
}

void setPinkColorForIndex(PlatformAgnosticPixel * color, int index){
	PlatformAgnosticPixel colors[] = {
		// Pink shades
		PlatformAgnosticPixel(255, 182, 193), // LightPink
		PlatformAgnosticPixel(255, 105, 180), // HotPink
		PlatformAgnosticPixel(255, 20, 147),  // DeepPink

	};
	*color = colors[index];
}

void setGoldColorForIndex(PlatformAgnosticPixel * color, int index){
  
	PlatformAgnosticPixel colors[] = {
		// Purple shades
		PlatformAgnosticPixel(128, 0, 128),   // Purple
		PlatformAgnosticPixel(147, 112, 219), // MediumPurple
		PlatformAgnosticPixel(138, 43, 226),  // BlueViolet
	};
	*color = colors[index];
}

void setGreenColorForIndex(PlatformAgnosticPixel * color, int index){
	PlatformAgnosticPixel colors[] = {

		// Green shades
		PlatformAgnosticPixel(0, 255, 0),     // Lime
		PlatformAgnosticPixel(0, 128, 0),     // Green
		PlatformAgnosticPixel(34, 139, 34)    // ForestGreen
	};
	*color = colors[index];
}