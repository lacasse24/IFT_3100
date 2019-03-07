// IFT3100H19_ShaderLambert/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"

#include "renderer.h"
#include "menugauche.h"
#include "ofxGui.h"
#include "ofxGifEncoder.h"

class Application : public ofBaseApp
{
public:

  Renderer renderer;

  menugauche menugauche;
  ofParameter<float> slider_hsb_degree;
  void setup();
  void update();
  void draw();
  void exit();

  void mouseMoved(int x, int y);
  void windowResized(int w, int h);

  void keyReleased(int key);

  void captureFrame();

  vector <ofTexture *> txs; // for previewing
  vector <ofxGifEncoder::ofxGifFrame *> pxs;

  int frameW, frameH;
  int nFrames;

  ofVideoGrabber vid;
  ofxGifEncoder gifEncoder;
  
};
