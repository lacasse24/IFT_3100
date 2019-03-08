#pragma once

#include "ofMain.h"
#include "..\Dependencies\soil\src\SOIL.h"
#include <iostream>
#include <vector>

class Skybox_Loader
{
public:

	void creeSkybox(GLuint* program, std::vector<char*> faces);
	void drawSkybox(glm::mat4 vue, glm::mat4 proj);

private:
	GLuint skyboxTexture;
	GLuint skyboxProgram;
	GLuint LumAmbiante;
	GLuint vaoCube, vboSommets;

	void drawCube(float largeur, float hauteur, float profondeur);
	GLuint loadCubemap(std::vector<char*> faces);
	unsigned char* ReadImage(char * filename);

	int width = 512;
	int height = 512;
	int canaux = 3;
};


