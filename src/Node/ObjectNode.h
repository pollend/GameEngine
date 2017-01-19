#ifndef _OBJECT_NODE_H_
#define  _OBJECT_NODE_H_

#include <map>
#include <string>
#include <Render/RenderObject.h>
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::Matrix4f;

class RenderObject;
class AttachmentNodeCallback;
class AttachmentNode;
class ObjectNode : public Node
{
private:
	std::map<std::string, AttachmentNodeCallback *> _attachmentNodeSet;
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
	virtual Matrix4f GetMatrix();

	/**
	*adds the attachment node callback to the object node
	**/
	void AddAttchmentNodeCallback(std::string nodeType,AttachmentNodeCallback* attachmentNodeCallback);

	/**
	*removes the attachment node from the callback based on the type
	**/
	void RemoveAndDeleteAttachmentNodeCallback(std::string nodeType);
	
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