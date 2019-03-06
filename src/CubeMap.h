#pragma once

#include "ofMain.h"

class CubeMap
{
public:
	CubeMap(string PosX, string negPosX, string PosY, string negPosY, string PosZ, string NegPosZ);
	~CubeMap();

	void LoadTexures(ofImage PosX, ofImage negPosX, ofImage PosY, ofImage negPosY, ofImage PosZ, ofImage NegPosZ);
	void LoadTexures(string PosX, string negPosX, string PosY, string negPosY, string PosZ, string NegPosZ);
	bool Load();
	void bind(GLenum TexUnit);

	GLuint getTexObj() { return m_TexObj; };

	unsigned int TextureO;


private:
	string m_TexDirectory[6];
	GLuint m_TexObj;
};