#pragma once

#include "ofMain.h"

class Skybox
{
public:

	void LoadTexures(ofImage PosX, ofImage negPosX, ofImage PosY, ofImage negPosY, ofImage PosZ, ofImage NegPosZ);
	void LoadTexures(string PosX, string negPosX, string PosY, string negPosY, string PosZ, string NegPosZ);
	bool Load();

	unsigned int Texture;


private:

};