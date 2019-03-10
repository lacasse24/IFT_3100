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


	// textures
	ofTexture Sun, Galaxy;
	ofTexture mTex ,imageTexture;
	ofTexture SBbk, SBfrnt, SBtop, SBbtm, SBleft, SBright;
	ofPoint points[4];


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
	void DrawSkyBox(ofTexture bk, ofTexture frnt, ofTexture top, ofTexture btm, ofTexture left, ofTexture right, int height);

private:
	Character* _character;
	vector<GameObject*> equipments;
	/* For debug purposes
	std::shared_ptr<Sword> _sword;
	std::shared_ptr<Helmet> _helmet;
	std::shared_ptr<Cape> _cape;
	std::shared_ptr<Armor> _armor;
	std::shared_ptr<Legging> _legging;
	std::shared_ptr<Boots> _boots;
	*/
};
