#ifndef _OBJECT_NODE_H_
#define  _OBJECT_NODE_H_

#include <map>
#include <string>
#include <Render/RenderObject.h>
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::Matrix4f;

class RenderObject;
class AttachmentNode;
class ObjectNode : public Node
{
private:
	RenderObject * _RenderObject;
public:
	//the origin of the object for the given item
	Vector3f Origin;

	ObjectNode(std::string ID);

	void SetRenderObject(RenderObject * renderObject, bool DeletePreviousRenderObject);

	RenderObject * GetRenderObject();

	virtual ~ObjectNode(void);

	/**
	*returns the matrix of the object
	**/
	virtual Matrix4f GetLocalTransform();

	/**
	*updates the object node
	**/
	virtual void Update();
	void Draw(Matrix4f transform, Matrix4f view);

	/**
	*returns the objects type for the given class object
	**/
	virtual std::string GetType();
};

#endif