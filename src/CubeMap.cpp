#include "CubeMap.h"

CubeMap::CubeMap(string PosX, string negPosX, string PosY, string negPosY, string PosZ, string NegPosZ)
{
	ofImage SkyTex[6];

	SkyTex[0].load(PosX);
	SkyTex[1].load(negPosX);
	SkyTex[2].load(PosY);
	SkyTex[3].load(negPosY);
	SkyTex[4].load(PosZ);
	SkyTex[5].load(NegPosZ);

	LoadTexures(SkyTex[0], SkyTex[1], SkyTex[2], SkyTex[3], SkyTex[4], SkyTex[5]);
}

CubeMap::~CubeMap()
{

}

void CubeMap::LoadTexures(string PosX, string negPosX, string PosY, string negPosY, string PosZ, string NegPosZ)
{
	
}


void CubeMap::LoadTexures(ofImage PosX, ofImage negPosX, ofImage PosY, ofImage negPosY, ofImage PosZ, ofImage NegPosZ)
{
	//create a texture object
	glGenTextures(1, &m_TexObj);
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, m_TexObj);

	const int img_size = PosX.getWidth();
	unsigned char *dataPosX, *dataNegPosX, *dataPosY, *dataNegPosY, *dataPosZ, *dataNegPosZ;

	dataPosX	= PosX.getPixels().getData();
	dataNegPosX = negPosX.getPixels().getData();
	dataPosY	= PosY.getPixels().getData();
	dataNegPosY = negPosY.getPixels().getData();
	dataPosZ	= PosZ.getPixels().getData();
	dataNegPosZ = NegPosZ.getPixels().getData();

	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataPosX);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataNegPosX);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataPosY);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataNegPosY);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataPosZ);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, dataNegPosZ);
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

bool CubeMap::Load()
{
	glGenTextures(1, &m_TexObj);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_TexObj);


	return true;
}