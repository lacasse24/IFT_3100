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
#include "../BoundingBox.h"
#include "../GameObject.h"
#include "./cursors/Cursor.h"

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

	ofBoxPrimitive box, boxSecond, boxThird, plancher,skybox, BBox;
	ofSpherePrimitive sphere,pedSphere1,pedSphere2;

	// textures
	ofTexture Sun, Galaxy;
	ofTexture mTex ,imageTexture;
	ofTexture SBbk, SBfrnt, SBtop, SBbtm, SBleft, SBright;
	ofPoint points[4];

	void drawCursor(Cursor* cursor);

	BoundingBox _BoundBox;

	GameObject* _Bird;
	int _Bird1X, _Bird1Y, _Bird1Z;
	BoundingBox _BirdBoundBox;

	GameObject* _Bird2;
	int _Bird2X, _Bird2Y, _Bird2Z;

	GameObject* _Bird3;
	int _Bird3X, _Bird3Y, _Bird3Z;

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
	void DrawSkyBox(ofTexture bk, ofTexture frnt, ofTexture top, ofTexture btm, ofTexture left, ofTexture right, int height);
	void DrawBoundingBox(ofxAssimpModelLoader model);

private:
	Character* _character;
	vector<GameObject*> equipments;
	GameObject* _sword;


};
