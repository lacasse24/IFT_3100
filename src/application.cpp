
#include "application.h"

void Application::setup()
{
  renderer.setup();
  menugauche.setup();

}

void Application::update()
{
  renderer.update();
  renderer.backgroundColor = menugauche.color_picker_background;
  renderer.updateModelShader(menugauche.slider_hsb_hue, menugauche.slider_hsb_saturation, menugauche.slider_hsb_brightness);
  renderer.guiHeight = menugauche.gui.getHeight();
  renderer.guiWidth = menugauche.gui.getWidth();
  renderer.previewImgName = menugauche.currentImgPath;

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

