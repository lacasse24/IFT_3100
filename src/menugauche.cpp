#include "menugauche.h"

void menugauche::setup()
{
	color = ofColor(255, 255, 255, 1);
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



	gui.add(color_picker_background);
	gui.add(&group_draw);
}

void menugauche::draw()
{
	gui.draw();
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