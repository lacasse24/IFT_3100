#include "menugauche.h"

void menugauche::setup()
{
	color = ofColor(255, 255, 255, 1);
	currentImgPath = "";

	// Initialisation des controles du menu
	gui.setup("Menu de dessin");
	color_picker_background.set("Couleur du fond", ofColor(31), ofColor(0, 0), ofColor(255, 255));

	slider_hsb_brightness.set("Luminosite", 0, 0, 100);
	slider_hsb_saturation.set("Saturation", 0,0,100);
	slider_hsb_hue.set("Teinte", 42, 0, 360);

	// Création de la hiéarchie dans le menu
	group_draw.setup("Couleur du modele");
	group_draw.add(slider_hsb_hue);
	group_draw.add(slider_hsb_saturation);
	group_draw.add(slider_hsb_brightness);

	//Pour la personalisation du personnage
	menuEquipments.setup("Equipments");

	menuHelm.setup("Helmets");
	menuHelm.add(btnGladiatorHelm.setup(""));
	setButton(btnGladiatorHelm, "Gladiator");
	

	menuSword.setup("Swords");
	menuSword.add(btnDHSword.setup(""));
	setButton(btnDHSword, "Sneaky");


	menuShield.setup("Shields");
	menuPlatebody.setup("Platebodies");
	menuPlatelegs.setup("Platelegs");
	menuBoots.setup("Boots");

	menuEquipments.add(&menuHelm);
	menuEquipments.add(&menuSword);
	menuEquipments.add(&menuShield);
	menuEquipments.add(&menuPlatebody);
	menuEquipments.add(&menuPlatelegs);
	menuEquipments.add(&menuBoots);

	group_draw.minimize();
	menuEquipments.minimize();

	gui.add(color_picker_background);
	gui.add(&group_draw);
	gui.add(&menuEquipments);
}

void menugauche::draw()
{
	gui.draw();
}
//, bool & pressed
void menugauche::btn_Pressed(const void * sender)
{
	ofParameter<bool> * v = (ofParameter<bool> *)sender;
	const string & name = v->getName();

	if (name == "Gladiator")
		currentImgPath = "helm.jpg";
	else if (name == "Sneaky")
		currentImgPath = "Sneaky.png";
	else
		currentImgPath = "";

	//currentImgPath = name;
}

void menugauche::update() 
{
	slider_hsb_brightness.set(color.getBrightness());
	slider_hsb_hue.set(color.getHue());
	slider_hsb_saturation.set(color.getSaturation());

	r = color.r;
	g = color.g;
	b = color.b;

	color_picker_background.set(color);
}

void menugauche::setButton(ofxButton &btn, string name)
{
	btn.setName(name);
	btn.addListener(this, &menugauche::btn_Pressed);
}
