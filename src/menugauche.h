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

	ofxGuiGroup menuEquipments;
	ofxGuiGroup menuHelm;
	ofxGuiGroup menuBoots;
	ofxGuiGroup menuShield;
	ofxGuiGroup menuPlatelegs;
	ofxGuiGroup menuPlatebody;
	ofxGuiGroup menuSword;

	ofxButton btnDHSword, btnGladiatorHelm;

	string currentImgPath;

	float r, g, b;

	void setup();

	void draw();
	void update();


	void setButton(ofxButton &btn, string name);
	void btn_Pressed(const void * sender);
	void convertHSBtoRGB();

};

