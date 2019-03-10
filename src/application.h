// IFT3100H19_ShaderLambert/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"
#include "renderer.h"
#include "menugauche.h"
#include "./cursors/AllCursorsHeader.h"
#include "ofxGui.h"


class Application : public ofBaseApp
{
public:

	Application();
	Renderer renderer;
	menugauche _menugauche;
	ofParameter<float> slider_hsb_degree;
	int positionx, positiony;
	void setup();
	void update();
	void draw();
	void exit();
	void mouseMoved(int x, int y);
	void windowResized(int w, int h);

	void keyReleased(int key);
  
};
