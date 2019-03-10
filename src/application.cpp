
#include "application.h"

Application::Application()
{
	normalcursor = new NormalCursor();
	_menugauche = menugauche(&renderer);
	ofHideCursor();
	isrecording = false;
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
	if (isrecording)
	{
		if ((ofGetFrameNum() - startednumberframe) % 60 == 0)
		{
			std::string imageName = std::to_string(frameCounter);
			
			ofImage image;
			image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			image.save("./gif/imagebuffer/"+imageName+".png");
			image.clear();
			frameCounter++;
		}
	}
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
	if (key == 'r')
	{
		if (isrecording)
		{
			std::string time_stamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");
			std::string debuts = "cd ./data/gif && ffmpeg.exe -f image2 -framerate 10 -i ./imagebuffer/%d.png  ./gifexported/"+time_stamp+ ".gif";
			const char* cstr = debuts.c_str();
			system(cstr);
			char* path = "./data/gif/imagebuffer/";
			std::experimental::filesystem::remove_all(path);
			fs::create_directories(path);
		}
		isrecording = !isrecording;
		startednumberframe = ofGetFrameNum();
		frameCounter = 0;
	}
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}



