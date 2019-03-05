#pragma once

#include "ofMain.h"
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

  string previewImgName = "",
	  currentImgName = "";

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


};
