#include "menugauche.h"

void menugauche::setup()
{
	color = ofColor(255, 255, 255, 1);
	// Initialisation des controles du menu
	gui.setup("Menu de dessin");
	color_picker_background.set("Couleur RGBA", ofColor(31), ofColor(0, 0), ofColor(255, 255));
	slider_hsb_brightness.set("Luminosité", 4, 0, 10);
	slider_hsb_saturation.set("Saturation", 4,0,10);
	slider_hsb_degree.set("Teinte", 180, 0, 360);

	// Création de la hiéarchie dans le menu
	group_draw.setup("Couleur HSB");
	group_draw.add(slider_hsb_degree);
	group_draw.add(slider_hsb_brightness);
	group_draw.add(slider_hsb_saturation);

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
	slider_hsb_degree.set(color.getHue());
	slider_hsb_saturation.set(color.getSaturation());

	color_picker_background.set(color);
}