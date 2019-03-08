#include "renderer.h"

void Renderer::setup()
{
	_character = new Character();
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
	_character->loadModel("basicman.obj");

	// désactiver le matériau par défaut du modèle
	//caracter.disableMaterials(); old
	_character->disableMaterials();

	// Important de faire cette etape avant de faire un setRotation
	_character->getTransform().addRotation(0.3f, 0.0f, 1.0f, 0.0f);

	// chargement du shader
	shader.load("lambert_330_vs.glsl", "lambert_330_fs.glsl");

}

void Renderer::update()
{
	// ofSetBackgroundColor(backgroundColor);

	if (previewImgName != currentImgName)
	{
		currentImgName = previewImgName;
		previewImg.load("Img/" + currentImgName);
	}

	// position au centre de la fenêtre d'affichage
	center_x = ofGetWidth() / 2.0f;
	center_y = ofGetHeight() / 2.0f;

	// transformation du caracter
	//caracter.setScale(0.5,1, 2);
	//caracter.setScale(scale_caracter, scale_caracter, scale_caracter); old
	_character->getTransform().setScale(scale_caracter, scale_caracter, scale_caracter);
	//caracter.setPosition(center_x, center_y + 90, 0); old
	_character->getTransform().setPosition(center_x, center_y + 90, 0);

	if (use_rotation)
	{
		_character->getTransform().setRotation(0, ofGetFrameNum() * 0.3f, 0.0f, 1.0f, 0.0f);
		//caracter.setRotation(0, ofGetFrameNum() * 0.3f, 0.0f, 1.0f, 0.0f); old
	}

	// configuration de la lumière
	light.setPointLight();
	light.setDiffuseColor(255);
	light.setGlobalPosition(center_x, center_y, 255.0f);
}

void Renderer::draw()
{
	// couleur d'arrière-plan
	ofClear(backgroundColor);

	// activer l'occlusion en profondeur
	ofEnableDepthTest();

	// activer l'éclairage dynamique
	ofEnableLighting();

	// activer la lumière
	light.enable();

	// activer le shader
	shader.begin();

	// dessiner le caracter
	//caracter.draw(OF_MESH_FILL); old
	_character->draw();

	// désactiver le shader
	shader.end();

	// désactiver la lumière
	light.disable();

	// désactiver l'éclairage dynamique
	ofDisableLighting();

	// désactiver l'occlusion en profondeur
	ofDisableDepthTest();

  font.drawString('(' + ofToString(mousePosX) + ';' + ofToString(mousePosY) + ')', winWidth - 130, 35);

  previewImg.draw(guiPosition.x, guiPosition.y + guiHeight + 10, 200, 200);
	
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
