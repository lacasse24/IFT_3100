#include "Skybox_loader.h"
#include<iostream>
#include<vector>

/****************Fonction permettant la création du skybox ********************/
void Skybox_Loader::creeSkybox(GLuint* program, std::vector<char*> faces)
{
	skyboxProgram = *program;

	glUseProgram(skyboxProgram);

	glGetUniformLocation(skyboxProgram, "UniIntensite");

	//Création du cube dans un VAO
	glGenVertexArrays(1, &vaoCube);
	glBindVertexArray(vaoCube);
	drawCube(1.0f, 1.0f, 1.0f);
	glBindVertexArray(0);

	//Création de la texture Cubemap
	skyboxTexture = loadCubemap(faces);
}

/******************Fonction permettant le dessin du skybox *********************/
void Skybox_Loader::drawSkybox(glm::mat4 vue, glm::mat4 proj)
{
	GLuint hprojection, hvue;

	glUseProgram(skyboxProgram);

	//Variables uniform du programme
	hprojection = glGetUniformLocation(skyboxProgram, "gProjection");
	assert(hprojection != 0xFFFFFFFF);
	hvue = glGetUniformLocation(skyboxProgram, "gVue");
	assert(hvue != 0xFFFFFFFF);

	glUniformMatrix4fv(hprojection, 1, GL_FALSE, &proj[0][0]);
	glUniformMatrix4fv(hvue, 1, GL_FALSE, &vue[0][0]);
	glUniform1f(LumAmbiante, 0.0f);

	// Appliquer la texture
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(glGetUniformLocation(skyboxProgram, "skybox"), 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTexture);

	//Dessiner le cube
	glBindVertexArray(vaoCube);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);


}

/*******************Fonction priv?e appel?e par creeSkybox() pour la cr?ation du cube du skybox ************/
void Skybox_Loader::drawCube(float largeur, float hauteur, float profondeur)
{
	GLfloat skyboxVertices[] = {
		// Positions          
		-largeur,  hauteur, -profondeur,// arri?re
		-largeur, -hauteur, -profondeur,
		largeur, -hauteur, -profondeur,
		largeur, -hauteur, -profondeur,
		largeur,  hauteur, -profondeur,
		-largeur,  hauteur, -profondeur,

		-largeur, -hauteur,  profondeur, //c?t? gauche
		-largeur, -hauteur, -profondeur,
		-largeur,  hauteur, -profondeur,
		-largeur,  hauteur, -profondeur,
		-largeur,  hauteur,  profondeur,
		-largeur, -hauteur,  profondeur,

		largeur, -hauteur, -profondeur, //c?t? droit
		largeur, -hauteur,  profondeur,
		largeur,  hauteur,  profondeur,
		largeur,  hauteur,  profondeur,
		largeur,  hauteur, -profondeur,
		largeur, -hauteur, -profondeur,

		-largeur, -hauteur,  profondeur, //avant
		-largeur,  hauteur,  profondeur,
		largeur,  hauteur,  profondeur,
		largeur,  hauteur,  profondeur,
		largeur, -hauteur,  profondeur,
		-largeur, -hauteur,  profondeur,


		largeur,  hauteur, -profondeur,	 //dessus
		largeur,  hauteur,  profondeur,
		-largeur,  hauteur,  profondeur,
		-largeur,  hauteur,  profondeur,
		largeur,  hauteur, -profondeur,
		-largeur,  hauteur, -profondeur,


		-largeur, -hauteur, -profondeur, //dessous
		-largeur, -hauteur,  profondeur,
		largeur, -hauteur, -profondeur,
		largeur, -hauteur, -profondeur,
		-largeur, -hauteur,  profondeur,
		largeur, -hauteur,  profondeur
	};

	GLuint skyboxVBO;
	glGenBuffers(1, &skyboxVBO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
}

GLuint Skybox_Loader::loadCubemap(std::vector<char*> faces)
{
	GLuint textureID;
	unsigned char* image;

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	//wrapping
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	//filtering
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	for (GLuint i = 0; i < faces.size(); i++)
	{
		image = ReadImage(faces[i]);

		//Ici, insérer le data de l'image dans le buffer
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, canaux, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

		SOIL_free_image_data(image);
	}
	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;

}

//GLuint Skybox_Loader::loadCubemap(std::vector<char*> faces)
//{
//	GLuint textureID;
//	unsigned char* image;
//
//	glGenTextures(1, &textureID);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
//
//	//wrapping
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//	//filtering
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//
//	for (GLuint i = 0; i < faces.size(); i++)
//	{
//		ofImage img;
//		//img.allocate(512, 512, OF_IMAGE_COLOR);
//		img.load(faces[i]);
//		int size = img.getWidth();
//		unsigned char *data = new unsigned char[512 * 512 * 3];
//		data = img.getPixels().getData();
//
//		//Ici, insérer le data de l'image dans le buffer
//		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, 3, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	}
//	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
//
//	return textureID;
//
//}

unsigned char* Skybox_Loader::ReadImage(char * filename)
{

	unsigned char* image = SOIL_load_image(filename, &width, &height, &canaux, SOIL_LOAD_AUTO);
	if (0 == image)
	{
		std::cout << "SOIL loading error: '%s'\n";
		std::cout << SOIL_last_result();
	}

	return image;
}
