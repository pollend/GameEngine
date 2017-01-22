#include "Node/Node.h"
#include "Camera.h"
#include "Node/SharedNodeInfo.h"
#include "Utility/Matrix/MatrixHelper.h"


using Eigen::Vector3f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;

Node::Node(std::string ID)
{
	_parentNode = NULL;

	Position = Vector3f();
	Scale = Vector3f(1,1,1);
	Rotation = Quaternionf();

	_id = ID;
}

Node::~Node(void)
{
	_sharedNodeInfo->mNodes->erase(_id);
}

std::string Node::GetID()
{
	return _id;
}

Matrix4f Node::GetTransformation()
{
	Matrix4f lfinal = GetLocalTransform();

	Node* node = GetParent();
	if(node != NULL)
	{
		lfinal = GetParent()->GetTransformation() * lfinal ;
	}
	return lfinal;
}


std::string Node::GetType(){
	return "Node";
}

Matrix4f Node::GetLocalTransform()
{
    Matrix4f lscale    = MatrixHelper::Scale(Scale);
    Matrix4f lposition = MatrixHelper::Translation(Position);
    Matrix4f lrotation = MatrixHelper::FromQuaternion(Rotation);
	return lscale  * lrotation * lposition;
}

void Node::SetParent(Node *n)
{
    _parentNode = n;

	//n->_parentNode = this;
	n->_sharedNodeInfo = _sharedNodeInfo;
	
	(*_sharedNodeInfo->mNodes)[n->_id] = n;

	n->_onNodeAppend();

}

void Node::_onNodeAppend(){

}


Node* Node::GetParent()
{
	return _parentNode;
}




void Node::Update()
{
}

