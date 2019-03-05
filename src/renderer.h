// IFT3100H19_ShaderLambert/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"


class Renderer
{
public:

  ofShader shader;

  ofLight light;

  ofxAssimpModelLoader caracter;

  float center_x;
  float center_y;

  float scale_caracter;

  bool use_rotation;

  void setup();
  void update();
  void draw();

  void updateshaderuniform(ofColor color);
};
