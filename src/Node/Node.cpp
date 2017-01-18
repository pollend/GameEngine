#include "Node/Node.h"
#include "Utility/Matrix/MatrixStack.h"
#include "Utility/Camera.h"
#include "Node/SharedNodeInfo.h"
#include "Utility/Matrix/MatrixHelper.h"
#include <Eigen/Geometry>


Node::Node(std::string ID)
{

	_parentNode = NULL;

	Position = Vector3f();
	Scale = Vector3f(1,1,1);
	Rotation = Quaternionf();

	_children =new std::list<Node*>();
	_id = ID;
}

Node::~Node(void)
{
	_sharedNodeInfo->mNodes->erase(_id);
	DeleteAllChildren();

	for(std::list<Node*>::iterator literator =  _parentNode->_children->begin(); literator != _parentNode->_children->end(); ++literator)
	{
		if((*literator)->GetID() == GetID())
		{
			_parentNode->_children->erase(literator);
		}
	}
	delete(_children);
}

std::string Node::GetID()
{
	return _id;
}

void Node::DeleteAllChildren()
{
	for(std::list<Node*>::iterator literator =  _children->begin(); literator != _children->end(); ++literator)
	{
		delete((*literator));
	}
	_children->clear();
}


void Node::DeleteChild(std::string id)
{
	for(std::list<Node*>::iterator literator =  _children->begin(); literator != _children->end(); ++literator)
	{
		if((*literator)->GetID() == id)
		{
			_children->erase(literator);
			delete((*literator));
		}
		
	}
}


std::string Node::GetType(){
	return "Node";
}

Matrix4f Node::GetMatrix()
{
    Matrix4f lscale    = MatrixHelper::Scale(Scale);
    Matrix4f lposition = MatrixHelper::Translation(Position);
    Matrix4f lrotation = Rotation.toRotationMatrix();
	return lscale  * lrotation * lposition;
}

void Node::AppendNode(Node * n)
{
	n->_parentNode = (this);
	n->_sceneNode = _sceneNode;
	n->_sharedNodeInfo = _sharedNodeInfo;
	
	(*_sharedNodeInfo->mNodes)[n->_id] = n;
	
	_children->push_back(n);

	n->_onNodeAppend();

}

void Node::_onNodeAppend(){
}

Node* Node::GetParent()
{
	return _parentNode;
}

Node* Node::GetNode(std::string id)
{

	for (std::list<Node*>::iterator it=_children->begin(); it != _children->end(); ++it)
	{
		if((*it)->GetID() == id)
		{
			return (*it);
		}
	}

}

std::list<Node*>*  Node::GetChildren()
{
	return _children;
}

Matrix4f Node::GetLocationOfNode(Camera* cam)
{
	MatrixStack lstack = MatrixStack();
	Node* llastParent = this;
	while (llastParent != NULL)
	{
		lstack.Push(llastParent->GetMatrix());
		llastParent = llastParent->GetParent();
	}
	lstack.Push(cam->GetMatrix());
	return lstack.GetReverseTransformMatrix();
}

void Node::Update()
{
}

