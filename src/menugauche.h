#pragma once
#include "renderer.h"
#include "ofxGui.h"
#include "ofMain.h"
#include "./cursors/AllCursorsHeader.h"


class menugauche
{
public:

	menugauche();
	menugauche(Renderer* renderer);
	Cursor* _cursor;
	SwordCursor* swordCursor;
	ChestPlateCursor* chestPlateCursor;
	LeggingsCursor* leggingsCursor;
	BootsCursor* bootsCursor;
	ShieldCursor* shieldCursor;
	HelmetCursor* helmetCursor;
	NormalCursor* normalCursor;

	Renderer* _renderer;
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

	ofxGuiGroup menuImport;
	ofxButton btnDHSword, btnGladiatorHelm, btnImportImg, btnImportModel, btnModelCategory;

	bool importImgOk, importModelOk, modelCategoryOk;

	string currentImgPath, importedImgPath, importedModelPath, importedModelCategory,importedImgName,importedImgType,currentModelPath;

	//ImportedImgPath and ImportedModelPath
	vector<tuple<string, string, string>>  importedModelInfos;


	bool verifyModelCategory(string category);
	float r, g, b;

	void setup();

	void draw(int positionx,int positiony);
	void update();
	vector<string> acceptedCategory;
	int importedModelCategoryIndex;
	void verifyEverythingOk();
	bool verifyExtension(string imgPath, vector<string> extensions);
	string stringToUpper(string str);
	void setButton(ofxButton &btn, string name);
	void btn_Pressed(const void * sender);
};

