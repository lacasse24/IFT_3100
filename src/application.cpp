// IFT3100H19_ShaderLambert/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  renderer.setup();
  menugauche.setup();

 /* menugauche.slider_hsb_brightness.addListener(this, &Application::menugaucheMouseReleaseHSB);
  menugauche.slider_hsb_degree.addListener(this, &Application::menugaucheMouseReleaseHSB);
  menugauche.slider_hsb_saturation.addListener(this, &Application::menugaucheMouseReleaseHSB);
  menugauche.color_picker_background.addListener(this, &Application::menugaucheMouseReleaseRGBA);*/
}

void Application::update()
{
  renderer.update();
  renderer.updateshaderuniform(menugauche.color);
}

void Application::draw()
{
  renderer.draw();
  menugauche.draw();
}

void Application::keyReleased(int key)
{
  renderer.use_rotation = !renderer.use_rotation;
}

void Application::menugaucheMouseReleaseHSB()
{
	menugauche.color.setHsb(menugauche.slider_hsb_degree.get(), 
								menugauche.slider_hsb_saturation.get(), 
								menugauche.slider_hsb_brightness.get());
}

void Application::menugaucheMouseReleaseRGBA() 
{
	menugauche.color.set(menugauche.color_picker_background->r, 
							menugauche.color_picker_background->g, 
							menugauche.color_picker_background->b, 
							menugauche.color_picker_background->a);
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}

