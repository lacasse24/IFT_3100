#include "renderer.h"




void Renderer::drawCursor(Cursor* pCursor)
{
	ofEnableAlphaBlending();
	pCursor->positionx = mousePosX;
	pCursor->positiony = mousePosY;
	pCursor->drawCursor();
}


void Renderer::setup()
{
	_character = new Character();
	_character->setup();

	_Bird = new GameObject();
	_Bird2 = new GameObject();
	_Bird3 = new GameObject();

	sphere.move(1400, 800, -2000);
	sphere.setRadius(120);
	//sphere.setPosition(ofGetWidth()*2, ofGetHeight()*.75, 10000);
	//cam.setTarget(skybox);
	//cam.setTarget(sphere);
	
	ofSetFrameRate(60);
	ofSetWindowShape(512, 512);
	backgroundColor.set(255);
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofEnableAlphaBlending();
	font.load("font/quicksand.otf", 18);

	// paramètres
	scale_caracter = 1.5f;
	use_rotation = true;

	// chargement du modèle
	//caracter.loadModel("basicman.obj"); old
	_character->loadModel("Lumberjack/Lumberjack2.fbx");
	//_owl->loadModel("Owl/Superb_Owl.fbx");

	_Bird->loadModel("Bird/Birdo.fbx");
	_Bird->disableMaterials();

	_Bird2->loadModel("Bird/Birdo.fbx");
	_Bird2->disableMaterials();

	_Bird3->loadModel("Bird/Birdo.fbx");
	_Bird3->disableMaterials();



	ofTexture t = _character->getMesh().getTextureForMesh(0);

	// Chargement textures
	ofLoadImage(SBbk,	"Img/SkyBox/siege_bk.tga");
	ofLoadImage(SBfrnt,	"Img/SkyBox/siege_ft.tga");
	ofLoadImage(SBtop,	"Img/SkyBox/siege_up.tga");
	ofLoadImage(SBbtm,	"Img/SkyBox/siege_dn.tga");
	ofLoadImage(SBleft, "Img/SkyBox/siege_lf.tga");
	ofLoadImage(SBright,"Img/SkyBox/siege_rt.tga");

	ofDisableArbTex();
	ofLoadImage(Sun, "Img/sun.png");

	box.setWidth(110);
	box.setHeight(110);
	boxSecond.setWidth(110);
	boxSecond.setHeight(70);
	boxThird.setWidth(110);
	boxThird.setHeight(50);
	pedSphere1.setRadius(50);
	pedSphere2.setRadius(50);

	// désactiver le matériau par défaut du modèle
	_character->disableMaterials();
	use_rotation = false;

	// Important de faire cette etape avant de faire un setRotation
	//_character->getTransform().addRotation(180.f, 1.0f, 0.0f, 0.0f);è

	// Oiseau 1
	_character->getTransform().addRotation(180.f, 0.0f, 0.0f, 1.0f);
	_character->getTransform().addRotation(0.f, 0.0f, 1.0f, 0.0f);

	_Bird->getTransform().addRotation(180.f, 0.0f, 0.0f, 1.0f);
	_Bird->getTransform().addRotation(90.f, 0.f, 1.f, 0.f);

	_Bird1X = -2000;
	_Bird1Y = 500;
	_Bird1Z = -700;

	_Bird->getTransform().setPosition(_Bird2X, _Bird2Y, _Bird2Z);

	// Oiseau 2
	_Bird2->getTransform().addRotation(180.f, 0.0f, 0.0f, 1.0f);
	_Bird2->getTransform().addRotation(-90.f, 0.f, 1.f, 0.f);

	_Bird2X = 1000;
	_Bird2Y = 900;
	_Bird2Z = -1200;

	_Bird2->getTransform().setPosition(_Bird2X, _Bird2Y, _Bird2Z);
	
	// Oiseau 2
	_Bird3->getTransform().addRotation(180.f, 0.0f, 0.0f, 1.0f);
	_Bird3->getTransform().addRotation(-90.f, 0.f, 1.f, 0.f);

	_Bird3X = -1000;
	_Bird3Y = 750;
	_Bird3Z = -1500;

	_Bird3->getTransform().setPosition(_Bird3X, _Bird3Y, _Bird3Z);
	

	// chargement du shader
	shader.load("lambert_330_vs.glsl", "lambert_330_fs.glsl");


	ofDisableAlphaBlending();
	ofEnableDepthTest();
	

	// Camera
	EasyCam.setFarClip(10000.f);

	/* For debug purposes
	_sword = std::make_shared<Sword>(Sword());
	_helmet = std::make_shared<Helmet>(Helmet());
	_cape = std::make_shared<Cape>(Cape());
	_armor = std::make_shared<Armor>(Armor());
	_legging = std::make_shared<Legging>(Legging());
	_boots = std::make_shared<Boots>(Boots());

	_sword->loadModel("testBox.obj");
	_helmet->loadModel("testBox.obj");
	_cape->loadModel("testBox.obj");
	_armor->loadModel("testBox.obj");
	_legging->loadModel("testBox.obj");
	_boots->loadModel("testBox.obj");

	_character->equipLeftHand(_sword);
	_character->equipHelmet(_helmet);
	_character->equipCape(_cape);
	_character->equipArmor(_armor);
	_character->equipLegging(_legging);
	_character->equipBoots(_boots);

	_sword->getTransform().setScale(.2, .2, .2);
	_helmet->getTransform().setScale(.2, .2, .2);
	_cape->getTransform().setScale(.2, .2, .2);
	_armor->getTransform().setScale(.2, .2, .2);
	_legging->getTransform().setScale(.2, .2, .2);
	_boots->getTransform().setScale(.2, .2, .2);
	*/

	//EasyCam.setDistance(300.f);
	//EasyCam.setGlobalPosition(glm::vec3(0.f, 0.f, 0.f));
	//EasyCam.rollDeg(180.f);
	//EasyCam.lookAt(_character->getMesh().getPosition());
	imageFiltre.load("./Img/saloon.jpg");

}


void Renderer::update()
{
	// ofSetBackgroundColor(backgroundColor);

	if (previewImgName != currentImgName)
	{
		currentImgName = previewImgName;
		if (previewImgName.size() < 20)
		{
			previewImg.load("Img/" + currentImgName);
		}
		else
		{
			previewImg.load(currentImgName);
		}
		
	}

	if (strEquipments.size() != lastSize)
	{
		tuple<string, string> lastElem = strEquipments[strEquipments.size() - 1];

		//Manque a mettre l'element à la bonne place (l'équiper)!
		if (std::get<1>(lastElem) == "Sword")
		{
			Sword* item = new Sword(std::get<0>(lastElem));
			equipments.push_back(item);
			//_character->equipLeftHand(make_shared<Sword>(*item));
		}
		else if (std::get<1>(lastElem) == "Armor")
		{
			Armor* item = new Armor(std::get<0>(lastElem));
			equipments.push_back(item);

		}
		else if (std::get<1>(lastElem) == "Legging")
		{
			Legging* item = new Legging(std::get<0>(lastElem));
			equipments.push_back(item);
		}
		else if (std::get<1>(lastElem) == "Boots")
		{
			Boots* item = new Boots(std::get<0>(lastElem));
			equipments.push_back(item);
		}
		else if (std::get<1>(lastElem) == "Shield")
		{
			Shield* item = new Shield(std::get<0>(lastElem));
			equipments.push_back(item);
		}
		else if (std::get<1>(lastElem) == "Helmet")
		{
			Helmet* item = new Helmet(std::get<0>(lastElem));
			equipments.push_back(item);
		}

		lastSize = strEquipments.size();
	}

	// position au centre de la fenêtre d'affichage
	center_x = ofGetWidth() / 2.0f;
	center_y = ofGetHeight() / 2.0f;

	// transformation du caracter

	_character->getTransform().setScale(scale_caracter, scale_caracter, scale_caracter);
	//caracter.setPosition(center_x, center_y + 90, 0); old
	_character->getTransform().setPosition(50, 0, 0);


	if (use_rotation)
	{
		_character->getTransform().setRotation(1, ofGetFrameNum() * 0.3f, 0.0f, 1.0f, 0.0f);
	}

	
	// Mouvement de l'oiseau 1
	_Bird->getTransform().setPosition(_Bird1X, _Bird1Y, _Bird1Z);
	if (_Bird1X > 2000) { _Bird1X = -2000; }
	else { _Bird1X += 10; }

	// Mouvement de l'oiseau 2
	_Bird2->getTransform().setPosition(_Bird2X, _Bird2Y, _Bird2Z);
	if (_Bird2X < -2000) { _Bird2X = 2000; }
	else { _Bird2X -= 7; }

	// Mouvement de l'oiseau 2
	_Bird3->getTransform().setPosition(_Bird3X, _Bird3Y, _Bird3Z);
	if (_Bird3X < -2000) { _Bird3X = 2000; }
	else { _Bird3X -= 11; }

	// configuration de la lumière
	light.setPointLight();
	light.setDiffuseColor(255);
	light.setGlobalPosition(center_x, center_y, 255.0f);
}

void Renderer::draw()
{

	EasyCam.begin();

	//ofClear(backgroundColor);

	// activer l'occlusion en profondeur
	ofEnableDepthTest();

	// activer l'éclairage dynamique
	ofEnableLighting();

	// activer la lumière
	light.enable();

	_character->draw();

	//_owl->draw();

	_Bird->draw();
	_Bird2->draw();
	_Bird3->draw();



	/* For debug purposes
	_sword.get()->draw();
	_helmet.get()->draw();
	_cape.get()->draw();
	_armor.get()->draw();
	_legging.get()->draw();
	_boots.get()->draw();
	*/
	
	ofPushStyle(); // push the current style for use later
	ofSetColor(backgroundColor);
	pedSphere1.draw();
	pedSphere2.draw();
	ofPopStyle();   // recall the pushed style

	int dimensionx = 850;
	int dimensiony = 400;
	imageFiltre.draw(dimensionx / -2, dimensiony / -2, -90, dimensionx, dimensiony);


	// activer le shader
	shader.begin();


	//_BoundBox.CalculateDelimitations(_character->getMesh());
	_BoundBox.draw(*_character).drawWireframe();



	for (int i = 0; i < equipments.size(); i++)
	{
		equipments[i]->draw();
	}

	aiVector3D pos = _character->getTransform().getPosition();


	box.setPosition(pos.x, pos.y - 240, pos.z);
	boxSecond.setPosition(pos.x - 110, pos.y - 240, pos.z);
	boxThird.setPosition(pos.x + 100, pos.y - 240, pos.z);
	pedSphere1.setPosition(pos.x - 110, pos.y - 160, pos.z);
	pedSphere2.setPosition(pos.x + 110, pos.y - 170, pos.z);


	box.draw();
	boxSecond.draw();
	boxThird.draw();


	// désactiver le shader
	shader.end();


	Sun.bind();
	sphere.draw();
	Sun.unbind();
	sphere.roll(1);

	//x,y,z,w,h
	DrawSkyBox(SBbk, SBfrnt, SBtop, SBbtm, SBleft, SBright, 5000);

	sphere.draw();

	// désactiver la lumière
	light.disable();

	// désactiver l'éclairage dynamique
	ofDisableLighting();

	// désactiver l'occlusion en profondeur
	ofDisableDepthTest();


	if (EasyCam.getDistance() > 1000) { EasyCam.setDistance(1000); }

	EasyCam.end();

	font.drawString('(' + ofToString(mousePosX) + ';' + ofToString(mousePosY) + ')', winWidth - 130, 35);
	previewImg.draw(guiPosition.x, guiPosition.y + guiHeight + 10, 200, 200);
}

void Renderer::DrawBoundingBox(ofxAssimpModelLoader model)
{

   previewImg.draw(guiPosition.x, guiPosition.y + guiHeight + 10, 200, 200);
   EasyCam.end();
	

}

void Renderer::DrawSkyBox(ofTexture bk, ofTexture frnt, ofTexture top, ofTexture btm, ofTexture left, ofTexture right, int height)
{
	int Half = height / 2;

	// Back
	ofPushMatrix();
	ofScale(-1, 1, 1);
	bk.draw(-Half, -Half, -Half, height, height);
	ofPopMatrix();
	

	// Front
	frnt.draw(-Half, -Half, Half, height, height);

	// Top
	ofPushMatrix();
	//ofScale(1, 1, -1);
	//ofScale(-1, 1, 1);
	ofRotateDeg(-90.f, 1.f, 0.f, 0.f);
	ofRotateDeg(-90.f, 0.f, 0.f, 1.f);
	top.draw(-Half, -Half, Half, height, height);
	//top.draw(0, 0, 0, height, height);
	ofPopMatrix();

	// Bottom
	ofPushMatrix();
	ofScale(-1, 1, 1);
	ofRotateDeg(-90.f, 1.0f, 0.f, 0.f);
	ofRotateDeg(-90.f, 0.f, 0.f, 1.f);
	btm.draw(-Half, -Half, -Half, height, height); 
	ofPopMatrix();

	// Left
	ofPushMatrix();
	ofRotateDeg(90.f, 0.f, 1.f, 0.f);
	left.draw(-Half, -Half, Half, height, height);
	ofPopMatrix();

	// Right
	ofPushMatrix();
	ofRotate(90.f, 0.f, 1.f, 0.f);
	ofScale(-1, 1, 1);
	right.draw(-Half, -Half, -Half, height, height);
	ofPopMatrix();
	
}

void Renderer::updateModelShader(float h, float s, float b)
{
	// passer les attributs uniformes du shader
	shader.begin();
	shader.setUniform3f("color_ambient", 0.1f, 0.1f, 0.1f);
	ofColor color = HSVtoRGB((int)h, (double)s,(double) b);
	//Le bug est ici ! J'essaie de tweaker pour avoir les bonnes couleurs ! Je crois qu'il va falloir convert la couleur du HSB en rgb et lui passer ! 
	shader.setUniform3f("color_diffuse",color.r/255.0f,color.g / 255.0f,color.b / 255.0f);
	shader.setUniform3f("light_position", glm::vec4(light.getGlobalPosition(), 0.0f) * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));
	shader.end();
}


//Méthode inspirée de la source : https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
ofColor Renderer::HSVtoRGB(int H, double S, double V) {
	ofColor color;
	double C = S * V;
	double X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
	double m = V - C;
	double Rs, Gs, Bs;

	if (H >= 0 && H < 60) {
		Rs = C;
		Gs = X;
		Bs = 0;
	}
	else if (H >= 60 && H < 120) {
		Rs = X;
		Gs = C;
		Bs = 0;
	}
	else if (H >= 120 && H < 180) {
		Rs = 0;
		Gs = C;
		Bs = X;
	}
	else if (H >= 180 && H < 240) {
		Rs = 0;
		Gs = X;
		Bs = C;
	}
	else if (H >= 240 && H < 300) {
		Rs = X;
		Gs = 0;
		Bs = C;
	}
	else {
		Rs = C;
		Gs = 0;
		Bs = X;
	}

	color.r = (Rs + m) * 255;
	color.g= (Gs + m) * 255;
	color.b = (Bs + m) * 255;
	return color;
}
void Renderer::filterinvert()
{
	
	
	imageFiltre.load("./Img/saloon.jpg");
	int x, y;
	int index;
	int imageHeight = imageFiltre.getHeight();
	int imageWith = imageFiltre.getWidth();
	ofImage invertimage;

	ofColor sourceColor;

	sourceColor.antiqueWhite;
	invertimage.allocate(imageFiltre.getWidth(), imageFiltre.getHeight(), OF_IMAGE_COLOR);

	ofPixels pixelsdest = invertimage.getPixels();
	ofPixels pixelssrc = imageFiltre.getPixels();

	pixelsdest.setColor(ofColor::white);
	for (y = 0; y < imageHeight; y++)
	{
		for (x = 0; x < imageWith; x++)
		{

			//index = (imageWith * y) + x;
			/*sourceColor = pixelssrc.getColor(index);
			pixelsdest.setColor(index, sourceColor.getInverted());*/
			ofColor color = pixelssrc.getColor(x%imageWith, y%imageHeight);
			color.invert();
			pixelsdest.setColor(x%imageWith, y%imageHeight, color);
		}
	}

	imageFiltre.setFromPixels(pixelsdest);
}

void Renderer::filterbackwhite()
{
	imageFiltre.load("./Img/saloon.jpg");
	int x, y;
	int imageHeight = imageFiltre.getHeight();
	int imageWith = imageFiltre.getWidth();
	int moyenne;
	ofPixels pixelsdest = imageFiltre.getPixels();
	ofPixels pixelssrc = imageFiltre.getPixels();

	for (y = 0; y < imageHeight; y++)
	{
		for (x = 0; x < imageWith; x++)
		{
			ofColor color = pixelssrc.getColor(x%imageWith, y%imageHeight);
			moyenne = (color.r + color.b + color.g) / 3;
			pixelsdest.setColor(x%imageWith, y%imageHeight, ofColor(moyenne,moyenne,moyenne,255));
		}
	}
	imageFiltre.setFromPixels(pixelsdest);
}

void Renderer::filterColourBlind()
{
	imageFiltre.load("./Img/saloon.jpg");
	int x, y;
	int random = rand() % 3;
	int imageHeight = imageFiltre.getHeight();
	int imageWith = imageFiltre.getWidth();
	ofPixels pixelsdest = imageFiltre.getPixels();
	ofPixels pixelssrc = imageFiltre.getPixels();

	for (y = 0; y < imageHeight; y++)
	{
		for (x = 0; x < imageWith; x++)
		{
			ofColor color = pixelssrc.getColor(x%imageWith, y%imageHeight);
			switch (random)
			{
			case 0 :
				color.r = 0;
				break;
			case 1 : 
				color.g = 0;
				break;
			case 2 :
				color.b = 0;
				break;
			}
			pixelsdest.setColor(x%imageWith, y%imageHeight, color);
		}
	}
	imageFiltre.setFromPixels(pixelsdest);
}
