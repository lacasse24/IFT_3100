#include "renderer.h"

void Renderer::setup()
{
	_character = new Character();
	//sphere.setPosition(ofGetWidth()*2, ofGetHeight()*.75, 10000);
	//cam.setTarget(skybox);
	sphere.move(100, 100, 200);
	//cam.setTarget(sphere);
	

	ofSetFrameRate(60);
	ofSetWindowShape(512, 512);
	ofSetBackgroundColor(220);
	ofSetLogLevel(OF_LOG_VERBOSE);

	font.load("font/quicksand.otf", 18);

	// paramètres
	scale_caracter = 1.5f;
	use_rotation = true;

	// chargement du modèle
	//caracter.loadModel("basicman.obj"); old
	_character->loadModel("Lumberjack/Lumberjack2.fbx");


	// désactiver le matériau par défaut du modèle
	_character->disableMaterials();
	use_rotation = false;

	// Important de faire cette etape avant de faire un setRotation
	_character->getTransform().addRotation(0.3f, 0.0f, 1.0f, 0.0f);
	
	

	// chargement du shader
	shader.load("lambert_330_vs.glsl", "lambert_330_fs.glsl");

	ofDisableAlphaBlending();
	ofEnableDepthTest();
	

	// Caméra
	//EasyCam.setDistance(300.f);
	//EasyCam.setGlobalPosition(glm::vec3(0.f, 0.f, 0.f));
	//EasyCam.rollDeg(180.f);
	//EasyCam.lookAt(_character->getMesh().getPosition());

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
			item->loadModel(std::get<0>(lastElem));

			//_character->equipLeftHand(make_shared<Sword>(item));
		}
		else if (std::get<1>(lastElem) == "Armor")
		{
			Armor* item = new Armor(std::get<0>(lastElem));
			equipments.push_back(item);
			item->loadModel(std::get<0>(lastElem));
		}
		else if (std::get<1>(lastElem) == "Legging")
		{
			Legging* item = new Legging(std::get<0>(lastElem));
			equipments.push_back(item);
			item->loadModel(std::get<0>(lastElem));
		}
		else if (std::get<1>(lastElem) == "Boots")
		{
			Boots* item = new Boots(std::get<0>(lastElem));
			equipments.push_back(item);
			item->loadModel(std::get<0>(lastElem));
		}
		else if (std::get<1>(lastElem) == "Shield")
		{
			Shield* item = new Shield(std::get<0>(lastElem));
			equipments.push_back(item);
			item->loadModel(std::get<0>(lastElem));
		}
		else if (std::get<1>(lastElem) == "Helmet")
		{
			Helmet* item = new Helmet(std::get<0>(lastElem));
			equipments.push_back(item);
			item->loadModel(std::get<0>(lastElem));
		}

		lastSize = strEquipments.size();
	}

	// position au centre de la fenêtre d'affichage
	center_x = ofGetWidth() / 2.0f;
	center_y = ofGetHeight() / 2.0f;

	// transformation du caracter

	_character->getTransform().setScale(scale_caracter, scale_caracter, scale_caracter);
	//caracter.setPosition(center_x, center_y + 90, 0); old
	_character->getTransform().setPosition(0, 0, 0);
	_character->getTransform().setRotation(0, 180.f, 1.0f, 0.0f, 0.0f);
	_character->getTransform().setRotation(0, 180.f, 0.0f, 0.0f, 1.0f);



	if (use_rotation)
	{
		_character->getTransform().setRotation(0, ofGetFrameNum() * 0.3f, 0.0f, 1.0f, 0.0f);
	}

	// configuration de la lumière
	light.setPointLight();
	light.setDiffuseColor(255);
	light.setGlobalPosition(center_x, center_y, 255.0f);
}

void Renderer::draw()
{
	EasyCam.begin();
	// couleur d'arrière-plan
	ofClear(backgroundColor);

	// activer l'occlusion en profondeur
	ofEnableDepthTest();

	// activer l'éclairage dynamique
	ofEnableLighting();

	// activer la lumière
	light.enable();
	_character->draw();

	// activer le shader
	shader.begin();

	// dessiner le caracter
	//caracter.draw(OF_MESH_FILL); old
	
	for (int i = 0; i < equipments.size(); i++)
	{
		equipments[i]->draw();
	}
	
	aiVector3D pos = _character->getTransform().getPosition();
	box.setWidth(110);
	box.setHeight(110);
	boxSecond.setWidth(110);
	boxSecond.setHeight(70);
	boxThird.setWidth(110);
	boxThird.setHeight(50);

	box.setPosition(pos.x, pos.y - 240, pos.z);
	boxSecond.setPosition(pos.x - 110, pos.y - 240, pos.z);
	boxThird.setPosition(pos.x + 100, pos.y - 240, pos.z);

	box.draw();
	boxSecond.draw();
	boxThird.draw();

	// désactiver le shader
	shader.end();

	//sphere.setRadius(1000);
	skybox.set(1000, 1000, 1000);
	//cam.begin();
	//cam.roll(1);

	ofDisableArbTex();
	ofLoadImage(mTex, "Img/galaxy.jpg");
	ofLoadImage(imageTexture, "Img/sun.png");
	//x,y,z,w,h
	
	imageTexture.draw(0, 0, 0, 1000, 1000);
	//imageTexture.draw(-500, -500, -500, 1000, 1000);
	//imageTexture.draw(-500, -500, 500, 1000, 1000);
	//imageTexture.draw(500, 0, 500, 1000, 1000);
	//imageTexture.draw(0, 0, -500, 1000, 1000);
	
	//imageTexture.draw(0, 0, 1000, 1000, 1000);


	//skybox.setSideColor(0, ofColor::red);
	//vector<ofMeshFace> triangles = skybox.getMesh().getFace;
	//mTex.bind();
	//skybox.draw();
	//sphere.draw();
	mTex.unbind();
	//cam.end();


	// désactiver la lumière
	light.disable();

	// désactiver l'éclairage dynamique
	ofDisableLighting();

	// désactiver l'occlusion en profondeur
	ofDisableDepthTest();
	
    font.drawString('(' + ofToString(mousePosX) + ';' + ofToString(mousePosY) + ')', winWidth - 130, 35);

   previewImg.draw(guiPosition.x, guiPosition.y + guiHeight + 10, 200, 200);

  EasyCam.end();
	
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
