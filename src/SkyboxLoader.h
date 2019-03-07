#pragma once

#include "ofMain.h"
#include <iostream>
#include <vector>

namespace Skybox
{
	class Skybox_Loader
	{
	public:

		void creeSkybox(GLuint* program, std::vector<char*> faces);
		void drawSkybox(glm::mat4 vue, glm::mat4 proj, bool Hit = false);

	private:
		GLuint skyboxTexture;
		GLuint skyboxProgram;
		GLuint LumAmbiante;
		GLuint vaoCube, vboSommets;

		void drawCube(float largeur, float hauteur, float profondeur);
		GLuint loadCubemap(std::vector<char*> faces);
	};
}


