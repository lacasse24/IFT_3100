#include "renderer.h"

void Renderer::setup()
{
  ofSetFrameRate(60);
  ofSetWindowShape(512, 512);
  ofSetBackgroundColor(220);
  ofSetLogLevel(OF_LOG_VERBOSE);

  font.load("font/quicksand.otf", 18);
  swordImg.load("Img/sword.png");

  // paramètres
  scale_caracter = 1.5f;
  use_rotation = true;

  // chargement du modèle
  caracter.loadModel("basicman.obj");

  // désactiver le matériau par défaut du modèle
  caracter.disableMaterials();

  // chargement du shader
  shader.load("lambert_330_vs.glsl", "lambert_330_fs.glsl");

}

void Renderer::update()
{
 // ofSetBackgroundColor(backgroundColor);

  // position au centre de la fenêtre d'affichage
  center_x = ofGetWidth() / 2.0f;
  center_y = ofGetHeight() / 2.0f;

  // transformation du caracter
  //caracter.setScale(0.5,1, 2);
  caracter.setScale(scale_caracter, scale_caracter, scale_caracter);
  caracter.setPosition(center_x, center_y + 90, 0);

  if (use_rotation)
    caracter.setRotation(0, ofGetFrameNum() * 0.3f, 0.0f, 1.0f, 0.0f);

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
  caracter.draw(OF_MESH_FILL);

  // désactiver le shader
  shader.end();

  // désactiver la lumière
  light.disable();

  // désactiver l'éclairage dynamique
  ofDisableLighting();

  // désactiver l'occlusion en profondeur
  ofDisableDepthTest();

 


  font.drawString('(' + ofToString(mousePosX) + ';' + ofToString(mousePosY) + ')', winWidth - 130, 35);
  swordImg.draw(100, 100, 50, 50);

}

void Renderer::updateModelShader(float h, float s, float b)
{
	// passer les attributs uniformes du shader
	shader.begin();
	shader.setUniform3f("color_ambient", 0.1f, 0.1f, 0.1f);
	//Le bug est ici ! J'essaie de tweaker pour avoir les bonnes couleurs ! Je crois qu'il va falloir convert la couleur du HSB en rgb et lui passer ! 
	shader.setUniform3f("color_diffuse",h / 360.0f, s / 100.0f, b / 100.0f); 
	shader.setUniform3f("light_position", glm::vec4(light.getGlobalPosition(), 0.0f) * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));
	shader.end();
}
