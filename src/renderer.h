#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "Skybox_Loader.h"
#include "Shader_Loader.h"


class Renderer
{
public:

  ofShader shader;
  ofImage previewImg;
  ofTrueTypeFont font;
  ofLight light;
  ofxAssimpModelLoader caracter;
  ofColor backgroundColor;

  ofCamera camera;
  float angle;
  float angleH, roll, distance;

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

  ofColor HSVtoRGB(int H, double S, double V);

  GLuint skyboxProgram;
  Skybox_Loader Skybox;
  ofShader ofSkybox;

  glm::vec3 g_Position = glm::vec3(0.0f, 0.0f, -30.0f);
  glm::vec3 g_Direction = glm::vec3(0.0f, 0.0f, 1.0f);
  glm::vec3 g_Orientation = glm::vec3(0.0f, 1.0f, 0.0f);
  GLfloat g_Yaw = 90.0f;
  GLfloat g_Pitch = 0.0f;


};
