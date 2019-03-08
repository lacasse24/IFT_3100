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
  ofImage swordImg;
  ofTrueTypeFont font;
  ofLight light;
  //ofxAssimpModelLoader caracter; old
  ofColor backgroundColor;

  float center_x;
  float center_y;
  float hue, saturation, brightness;

  int mousePosX;
  int mousePosY;
  int winWidth;
  int winHeight;

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
