#pragma once
#include "renderer.h"
#include "ofxGui.h"
#include "ofMain.h"

class menugauche
{
public:

	ofColor color;

	ofxPanel gui;

	ofxGuiGroup group_draw;

	ofParameter<ofColor> color_picker_background;

	ofParameter<float> slider_hsb_hue;

	ofParameter<float> slider_hsb_saturation;

	ofParameter<float> slider_hsb_brightness;

	float r, g, b;

	void setup();

	void draw();

	void update();
};

