// IFT3100H19_ShaderLambert/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"
#include "renderer.h"
#include "menugauche.h"
#include "./cursors/AllCursorsHeader.h"
#include "ofxGui.h"

#include <iostream>
#include <cstdint>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;




class Application : public ofBaseApp
{
public:

	Application();
	Renderer renderer;
	menugauche _menugauche;
	NormalCursor* normalcursor;
	ofParameter<float> slider_hsb_degree;
	int positionx, positiony;
	void setup();
	void update();
	void draw();
	void exit();
	void mouseMoved(int x, int y);
	void windowResized(int w, int h);
	void Application::mouseReleased(int x, int y, int button);
	void keyReleased(int key);
	int startednumberframe;
	int frameCounter;
	bool isrecording;
  
};
