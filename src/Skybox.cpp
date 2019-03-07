#include "Skybox.h"

Skybox::Skybox()
{

}

Skybox::~Skybox()
{

}

void Skybox::LoadTexures(string PosX, string negPosX, string PosY, string negPosY, string PosZ, string NegPosZ)
{
	ofImage SkyTex[6];

	SkyTex[0].loadImage(PosX);
	SkyTex[1].loadImage(negPosX);
	SkyTex[2].loadImage(PosY);
	SkyTex[3].loadImage(negPosY);
	SkyTex[4].loadImage(PosZ);
	SkyTex[5].loadImage(NegPosZ);

	LoadTexures(SkyTex[0], SkyTex[1], SkyTex[2], SkyTex[3], SkyTex[4], SkyTex[5]);
}


void Skybox::LoadTexures(ofImage PosX, ofImage negPosX, ofImage PosY, ofImage negPosY, ofImage PosZ, ofImage NegPosZ)
{
	//create a texture object
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, Texture);

	const int img_size = PosX.getWidth();
	unsigned char *dataPosX, *dataNegPosX, *dataPosY, *dataNegPosY, *dataPosZ, *dataNegPosZ;

	dataPosX	= PosX.getPixels().getData();
	dataNegPosX = negPosX.getPixels().getData();
	dataPosY	= PosY.getPixels().getData();
	dataNegPosY = negPosY.getPixels().getData();
	dataPosZ	= PosZ.getPixels().getData();
	dataNegPosZ = NegPosZ.getPixels().getData();

	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataPosX);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataNegPosX);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataPosY);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataNegPosY);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataPosZ);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataNegPosZ);
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

bool Skybox::Load()
{
	return true;
}