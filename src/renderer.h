#pragma once

#include "ofMain.h"
#include "ofxSkyBox.h"
#include "ofxAssimpModelLoader.h"


class Renderer
{
public:

  ofShader shader;
  ofImage previewImg;
  ofTrueTypeFont font;
  ofLight light;
  ofxAssimpModelLoader caracter;
  ofColor backgroundColor;
  ofxSkyBox  skybox;
  ofCamera camera;

  ofPoint guiPosition;
  ofVec3f sphereCenter;

  string previewImgName = "",
	  currentImgName = "";

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

  void updateModelShader(float h, float s, float b);

  ofColor HSVtoRGB(int H, double S, double V);


};
