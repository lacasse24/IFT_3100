
#include "application.h"

Application::Application()
{
	normalcursor = new NormalCursor();
	_menugauche = menugauche(&renderer);
	ofHideCursor();
}

void Application::setup()
{
  renderer.setup();
  _menugauche.setup();
  
}

void Application::update()
{
	renderer.update();
	renderer.backgroundColor = _menugauche.color_picker_background;
	renderer.updateModelShader(_menugauche.slider_hsb_hue, _menugauche.slider_hsb_saturation, _menugauche.slider_hsb_brightness);
	renderer.guiHeight = _menugauche.gui.getHeight();
	renderer.guiPosition = _menugauche.gui.getPosition();
	renderer.previewImgName = _menugauche.currentImgPath;

	if (_menugauche.currentModelPath != "" && _menugauche.currentModelPath != renderer.lastImportedModelPath)
	{
		renderer.strEquipments.push_back(make_tuple(_menugauche.currentModelPath, _menugauche.importedImgType));
		renderer.lastImportedModelPath = _menugauche.importedModelPath;
	}
}

void Application::draw()
{
	renderer.draw();
	_menugauche.draw(positionx, positiony);
	
  
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

void Application::mouseReleased(int x, int y, int button)
{
	_menugauche._cursor = normalcursor;
}

void Application::keyReleased(int key)
{
  renderer.use_rotation = !renderer.use_rotation;
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}

