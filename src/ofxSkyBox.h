
#ifndef	SKY_BOX_H
#define SKY_BOX_H

#include "ofMain.h"
#include "ofxCubeMap.h"


class ofxSkyBox
{


public:

	ofxSkyBox();
    void load();
	void draw();
    void  Draw_Skybox(float x, float y, float z, float width, float height, float length);
    ofxCubeMap cubeMap;
	ofShader cubeshader;

};

#endif
