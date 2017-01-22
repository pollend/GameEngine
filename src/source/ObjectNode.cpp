#include "Node/ObjectNode.h"
#include "Utility/Matrix/MatrixHelper.h"

ObjectNode::ObjectNode(std::string ID) : Node::Node(ID)
{
	Origin = Vector3f(0,0,0);
	_RenderObject = NULL;
}

Matrix4f ObjectNode::GetLocalTransform()
{
	Matrix4f lscale =  MatrixHelper::Scale(Scale);
	Matrix4f lrotation = MatrixHelper::FromQuaternion(Rotation);

	Matrix4f lposition = MatrixHelper::Translation(Position);
	Matrix4f lorigin = MatrixHelper::Translation(Origin.reverse());
	return lorigin * lscale  * lrotation * lposition;
}
ObjectNode::~ObjectNode(void)
{
}

void ObjectNode::SetRenderObject(RenderObject * renderObject, bool DeletePreviousRenderObject)
{
	if(DeletePreviousRenderObject && _RenderObject != NULL)
	delete(_RenderObject);
	_RenderObject = renderObject;
}

void ObjectNode::Update()
{
}

RenderObject * ObjectNode::GetRenderObject()
{
	return _RenderObject;
}


std::string ObjectNode::GetType()
{
	return "object_node";
}

void ObjectNode::Draw(Matrix4f transform, Matrix4f view)
{
	//draws the render object
	_RenderObject->Draw(transform,view);
}