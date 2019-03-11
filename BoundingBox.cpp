#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
	GameObject::GameObject();
	MinX = MaxX = MinY = MaxY = MinZ = MaxZ = 0;
}

ofBoxPrimitive BoundingBox::CalculateDelimitations(ofxAssimpModelLoader Mesh, ofBoxPrimitive BoundBox)
{
	std::vector<glm::vec3> MeshVertices = Mesh.getMesh(0).getVertices();

	for (int i = 0; i < MeshVertices.size(); i++)
	{
		float posx = MeshVertices[i].x;
		float posy = MeshVertices[i].y;
		float posz = MeshVertices[i].z;

		// Vertex en X
		if (posx < MinX) { MinX = posx; }
		if (posx > MaxX) { MaxX = posx; }

		// Vertex en Y
		if (posy < MinY) { MinY = posy; }
		if (posy > MaxY) { MaxY = posy; }

		// Vertex en Z
		if (posz < MinZ) { MinZ = posz; }
		if (posz > MaxZ) { MaxZ = posz; }
	}

	float sizeX = std::abs(MaxX - MinX);
	float SizeY = std::abs(MaxY - MinY);
	float SizeZ = std::abs(MaxZ - MinZ);

	BoundBox.setWidth(sizeX);
	BoundBox.setHeight(SizeY);
	BoundBox.setDepth(SizeZ);

	BoundBox.setPosition(MinX, MinY, MinZ);

	return BoundBox;
}

ofBoxPrimitive BoundingBox::draw(GameObject obj)
{
	ofBoxPrimitive BoundBox;
	BoundBox = CalculateDelimitations(obj.getMesh(), BoundBox);

	GameObject::draw();
	_BoundBox.resetTransform();

	// Rotate
	std::vector< std::pair<float, aiVector3D> > Rot = obj.getTransform().getRotations();
	for (int i = 1; i < Rot.size(); i++)
	{
		BoundBox.rotateDeg(Rot[i].first, Rot[i].second.x, Rot[i].second.y, Rot[i].second.z);
		//_BoundBox.rotate(glm::quat(Rot[i].first, Rot[i].second.x, Rot[i].second.y, Rot[i].second.z));
	}

	// Translate
	aiVector3D Trans = obj.getTransform().getPosition();
	BoundBox.setGlobalPosition(glm::vec3(Trans.x, Trans.y, Trans.z));

	aiVector3D Scale = obj.getTransform().getScale();
	BoundBox.setScale(glm::vec3(Scale.x, Scale.y, Scale.z));



	BoundBox.setScale(205.f);
	//BoundBox.setScale(2.f);
	//_BoundBox.drawWireframe();

	return BoundBox;
}