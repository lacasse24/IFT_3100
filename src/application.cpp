// IFT3100H19_ShaderLambert/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  renderer.setup();
  menugauche.setup();

}

void Application::update()
{
  renderer.update();
  //renderer.updateshaderuniform(menugauche.color);
  renderer.backgroundColor = menugauche.color_picker_background;
  renderer.updateModelShader(menugauche.slider_hsb_hue, menugauche.slider_hsb_saturation, menugauche.slider_hsb_brightness);
//  renderer.brightness = menugauche.color.get
 // renderer.hue = menugauche.slider_hsb_hue;
 // renderer.saturation = menugauche.slider_hsb_saturation;
}

void Application::draw()
{
  renderer.draw();
  menugauche.draw();
}

void Application::mouseMoved(int x, int y)
{
	renderer.mousePosX = x;
	renderer.mousePosY = y;
}

void Application::windowResized(int w, int h)
{
	renderer.winHeight = h;
	renderer.winWidth = w;
}

void Application::keyReleased(int key)
{
  renderer.use_rotation = !renderer.use_rotation;
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}

