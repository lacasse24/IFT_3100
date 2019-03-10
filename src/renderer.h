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
#include "../GameObject.h"

class Renderer
{
public:

	ofShader shader;
	ofImage previewImg;
	ofTrueTypeFont font;
	ofLight light;
	ofEasyCam cam;
	ofxAssimpModelLoader caracter;
	ofColor backgroundColor;
	ofPoint guiPosition;
	std::string previewImgName = "", currentImgName = "", lastImportedModelPath,importedModelCategory;
	vector<tuple<string, string>> strEquipments;

	ofEasyCam EasyCam;
	ofBoxPrimitive box, boxSecond, boxThird, plancher,skybox;
	ofSpherePrimitive sphere;

	ofTexture mTex ,imageTexture;
	ofPoint points[4];

	float center_x;
	float center_y;
  
	int guiHeight;
	int mousePosX, mousePosY;
	int winWidth, winHeight;

	float scale_caracter;

	bool use_rotation;

	void setup();
	void update();
	void draw();

	int lastSize = 0;
	void updateModelShader(float h, float s, float b);
	ofColor HSVtoRGB(int H, double S, double V);

private:
	Character* _character;
	vector<GameObject*> equipments;
	GameObject* _sword;


};
