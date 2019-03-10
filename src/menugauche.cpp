#include "menugauche.h"

menugauche::menugauche()
{
}
menugauche::menugauche(Renderer* renderer)
{
	_renderer = renderer;
	swordCursor = new SwordCursor();
	chestPlateCursor = new ChestPlateCursor();
	leggingsCursor = new LeggingsCursor();
	bootsCursor = new BootsCursor();
	shieldCursor = new ShieldCursor();
	helmetCursor = new HelmetCursor();
	normalCursor = new NormalCursor();
	_cursor = normalCursor;
}
void menugauche::setup()
{
	acceptedCategory = { stringToUpper("Armor"),stringToUpper("Legging"),stringToUpper("Boots"),stringToUpper("Helmet"),stringToUpper("Shield"),stringToUpper("Sword") };
	color = ofColor(255, 255, 255, 1);
	currentImgPath = "";

	// Initialisation des controles du menu
	gui.setup("Tools");
	color_picker_background.set("Background color", ofColor(31), ofColor(0, 0), ofColor(255, 255));

	slider_hsb_brightness.set("Hue", 0, 0, 100);
	slider_hsb_saturation.set("Saturation", 0, 0, 100);
	slider_hsb_hue.set("Brightness", 42, 0, 360);

	// Création de la hiéarchie dans le menu
	group_draw.setup("Model color");
	group_draw.add(slider_hsb_hue);
	group_draw.add(slider_hsb_saturation);
	group_draw.add(slider_hsb_brightness);

	//Pour la personalisation du personnage
	menuEquipments.setup("Equipments");

	menuHelm.setup("Helmet");
	menuHelm.add(btnGladiatorHelm.setup(""));
	setButton(btnGladiatorHelm, "Gladiator");


	menuSword.setup("Swords");
	menuSword.add(btnDHSword.setup(""));
	setButton(btnDHSword, "Sneaky");

	
	menuShield.setup("Shield");
	menuPlatebody.setup("Armor");
	menuPlatelegs.setup("Legging");
	menuBoots.setup("Boots");

	menuEquipments.add(&menuHelm);
	menuEquipments.add(&menuSword);
	menuEquipments.add(&menuShield);
	menuEquipments.add(&menuPlatebody);
	menuEquipments.add(&menuPlatelegs);
	menuEquipments.add(&menuBoots);

	group_draw.minimize();
	menuEquipments.minimize();

	menuImport.setup("Import a new model");
	menuImport.add(btnImportImg.setup(""));
	menuImport.add(btnImportModel.setup(""));
	menuImport.add(btnModelCategory.setup(""));
	setButton(btnImportImg, "Import image");
	setButton(btnImportModel, "Import model");
	setButton(btnModelCategory, "Model category");



	gui.add(&menuImport);
	gui.add(color_picker_background);
	gui.add(&group_draw);
	gui.add(&menuEquipments);

	

}

void menugauche::draw(int positionx,int positiony)
{
	gui.draw();
	_renderer->mousePosX = ofGetMouseX();
	_renderer->mousePosY = ofGetMouseY();
	_renderer->drawCursor(_cursor);
}
//, bool & pressed
void menugauche::btn_Pressed(const void * sender)
{
	ofParameter<bool> * v = (ofParameter<bool> *)sender;
	const string & name = v->getName();

	if (name == "Gladiator")
	{
		currentImgPath = "helm.jpg";
		_cursor = helmetCursor;
	}
	else if (name == "Sneaky")
	{
		currentImgPath = "Sneaky.png";
		_cursor = swordCursor;
	}
	else if (name == "Import image")
	{
		ofFileDialogResult result = ofSystemLoadDialog("Charger l'image du modele");
		if (result.bSuccess)
		{
			vector<string> possibleExtensions;
			possibleExtensions.push_back(stringToUpper("png"));
			possibleExtensions.push_back(stringToUpper("jpg"));
			possibleExtensions.push_back(stringToUpper("jpeg"));

			if (verifyExtension(result.getName(), possibleExtensions) == true)
			{
				importedImgPath = result.getPath();
				importImgOk = true;
				verifyEverythingOk();
			}
			else
			{
				ofSystemAlertDialog("The extension isn't valid,the specified file must be a jpg,jpeg or png. Please retry.");
			}

		}
	}
	else if (name == "Import model")
	{
		ofFileDialogResult result = ofSystemLoadDialog("Charger le modele");
		if (result.bSuccess)
		{
			vector<string> possibleExtensions;
			possibleExtensions.push_back(stringToUpper("obj"));
			possibleExtensions.push_back(stringToUpper("ply"));

			if (verifyExtension(result.getName(), possibleExtensions) == true)
			{
				importedModelPath = result.getPath();
				importModelOk = true;
				verifyEverythingOk();
			}
			else
			{
				ofSystemAlertDialog("The extension isn't valid,the specified file must be an obj or ply. Please retry.");
			}
		}
	}
	else if (name == "Model category")
	{
		string modelCategory = ofSystemTextBoxDialog("Enter the category", "");

		if (verifyModelCategory(modelCategory) == true)
		{
			importedModelCategory = modelCategory;
			modelCategoryOk = true;
			verifyEverythingOk();
		}
		else
		{
			ofSystemAlertDialog("This category doesn't exist . Please retry.");
		}
	}
	else
		currentImgPath = "";

}


bool menugauche::verifyModelCategory(string category)
{
	int x = 0;
	bool isOk = false;

	while (x < acceptedCategory.size())
	{
		if (acceptedCategory[x] == stringToUpper(category))
		{
			isOk = true;
			importedModelCategoryIndex = x;
		}
		x++;
	}

	return isOk;
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

void menugauche::verifyEverythingOk()
{
	vector<string> types = { "Armor","Legging","Boots","Helmet","Shield","Sword" };

	if (importImgOk & importImgOk & modelCategoryOk)
	{
		importedModelInfos.push_back(std::make_tuple(importedImgPath, importedModelPath, importedModelCategory));
		
		currentImgPath = importedImgPath;
		currentModelPath = importedModelPath;
		importedImgType = types[importedModelCategoryIndex];
	
		
		//importImgOk = false;
		//importModelOk = false;
		//modelCategoryOk = false;
	}
}

string menugauche::stringToUpper(string str)
{
	for (auto & c : str) c = toupper(c);

	return str;
}

bool menugauche::verifyExtension(string imgPath, vector<string> extensions)
{
	string delimiter = ".";
	string extension = "";
	bool isOk = false;

	int dotIndex = imgPath.find(delimiter);

	for (int i = 0; i < dotIndex; i++)
	{
		importedImgName += toupper(imgPath[i]);
	}

	for (int i = dotIndex + 1; i < imgPath.size(); i++)
	{
		extension += toupper(imgPath[i]);
	}

	for (int i = 0; i < extensions.size(); i++)
	{
		if (extensions[i] == extension)
			isOk = true;
	}

	return isOk;
}

void menugauche::setButton(ofxButton &btn, string name)
{
	btn.setName(name);
	btn.addListener(this, &menugauche::btn_Pressed);
}
