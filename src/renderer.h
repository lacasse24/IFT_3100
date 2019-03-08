#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

#include "../Character.h"
#include "../Shield.h"
#include "../Sword.h"
#include "../Helmet.h"
#include "../Cape.h"
#include "../Armor.h"
#include "../Boots.h"

class Renderer
{
public:

	ofShader shader;
	ofImage previewImg;
	ofTrueTypeFont font;
	ofLight light;
	ofxAssimpModelLoader caracter;
	ofColor backgroundColor;

	std::string previewImgName = "", currentImgName = "";

	float center_x;
	float center_y;
  
	int guiHeight, guiWidth;
	int mousePosX, mousePosY;
	int winWidth, winHeight;

	float scale_caracter;

	bool use_rotation;

	void setup();
	void update();
	void draw();

	void updateModelShader(float h, float s, float b);

	ofColor HSVtoRGB(int H, double S, double V);

private:
	GameObject* _character;


};
