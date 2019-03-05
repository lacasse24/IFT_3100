#pragma once

#include "ofxGui.h"
#include "ofMain.h"

class menugauche
{
public:

	ofColor color;

	ofxPanel gui;

	ofxGuiGroup group_draw;

	ofParameter<ofColor> color_picker_background;

	ofParameter<float> slider_hsb_degree;

	ofParameter<float> slider_hsb_saturation;

	ofParameter<float> slider_hsb_brightness;

	void setup();

	void draw();

	void update();
};

