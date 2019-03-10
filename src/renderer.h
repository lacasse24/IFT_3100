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
#include "./cursors/Cursor.h"

class Renderer
{
public:

	Renderer();
	ofShader shader;
	ofImage previewImg;
	ofTrueTypeFont font;
	ofLight light;
	ofxAssimpModelLoader caracter;
	ofColor backgroundColor;
	ofPoint guiPosition;
	std::string previewImgName = "", currentImgName = "", lastImportedModelPath,importedModelCategory;
	vector<tuple<string, string>> strEquipments;

	void drawCursor(Cursor* cursor);
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
	int mouse_current_x;
	int mouse_current_y;
	int lastSize = 0;
	void updateModelShader(float h, float s, float b);
	ofColor HSVtoRGB(int H, double S, double V);

private:
	Character* _character;
	vector<GameObject*> equipments;
	GameObject* _sword;


};
