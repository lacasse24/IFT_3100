#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "GameObjects/Character.h"
#include "GameObjects/Shield.h"
#include "GameObjects/Sword.h"
#include "GameObjects/Helmet.h"
#include "GameObjects/Cape.h"
#include "GameObjects/Armor.h"
#include "GameObjects/Boots.h"
#include "GameObjects/GameObject.h"
#include "./cursors/Cursor.h"

class Renderer
{
public:
	//----------------------------------------------------------------------------
	// ------------ Variables
	

	// ------------ objets OF
	ofShader shader;
	ofLight light;
	ofEasyCam EasyCam;
	ofTrueTypeFont font;
	ofColor backgroundColor;

	// ------------ objets GUI
	ofPoint guiPosition;
	float center_x;
	float center_y;

	int guiHeight;
	int mousePosX, mousePosY;
	int winWidth, winHeight;

	// ------------ Images
	ofImage imageFiltre;
	ofImage previewImg;
	
	// ------------ Géométrie	
	ofBoxPrimitive box, boxSecond, boxThird, plancher,skybox, BBox;
	ofSpherePrimitive sphere,pedSphere1,pedSphere2;
	float scale_caracter;

	GameObject* _Bird;
	int _Bird1X, _Bird1Y, _Bird1Z;

	GameObject* _Bird2;
	int _Bird2X, _Bird2Y, _Bird2Z;

	GameObject* _Bird3;
	int _Bird3X, _Bird3Y, _Bird3Z;

	// ------------ textures
	ofTexture Sun, Galaxy;
	ofTexture mTex ,imageTexture;
	ofTexture SBbk, SBfrnt, SBtop, SBbtm, SBleft, SBright;

	// ------------ Autre
	std::string previewImgName = "", 
				currentImgName = "", 
				lastImportedModelPath, 
				importedModelCategory;

	ofPoint points[4];

	vector<tuple<string, string>> strEquipments;

	

	bool use_rotation;

	//----------------------------------------------------------------------------
	// ------------ Fonctions
	void setup();
	void update();
	void draw();
	int mouse_current_x;
	int mouse_current_y;
	int lastSize = 0;
	void updateModelShader(float h, float s, float b);
	void filterColourBlind();
	ofColor HSVtoRGB(int H, double S, double V);
	void DrawSkyBox(ofTexture bk, ofTexture frnt, ofTexture top, ofTexture btm, ofTexture left, ofTexture right, int height);
	void filterinvert();
	void filterbackwhite();
	void drawCursor(Cursor* cursor);

	void DrawBoundingBox(ofxAssimpModelLoader model);

private:
	Character* _character;
	vector<GameObject*> equipments;
	//* For debug purposes
	std::shared_ptr<Sword> _sword;
	std::shared_ptr<Shield> _shield;
	std::shared_ptr<Helmet> _helmet;
	std::shared_ptr<Cape> _cape;
	std::shared_ptr<Armor> _armor;
	std::shared_ptr<Legging> _legging;
	std::shared_ptr<Boots> _boots;
	/**/
};
