// IFT3100H19_ShaderLambert/application.cpp
// Classe principale de l'application.

#include "application.h"

void Application::setup()
{
  renderer.setup();
  menugauche.setup();
  gifEncoder.setup(ofGetWindowWidth(), ofGetWindowHeight(), 60*14, 8);

}

void Application::update()
{
  renderer.update();

  renderer.backgroundColor = menugauche.color_picker_background;
  renderer.updateModelShader(menugauche.slider_hsb_hue.get(),menugauche.slider_hsb_saturation.get(),menugauche.slider_hsb_brightness.get());

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

void Application::captureFrame()
{
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}

