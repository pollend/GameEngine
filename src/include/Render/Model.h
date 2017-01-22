#ifndef _MODEL_H_
#define _MODEL_H_

#include <VertexObject/VertexBufferObjectWithSubData.h>
#include <VertexObject/VertexElementBuffer.h>
#include "RenderObject.h"
#include <Eigen/Dense>

using Eigen::Matrix4f;
class Model :public RenderObject
{
private:
	VertexBufferObjectWithSubData * _vertexBufferObject;
	VertexElementBuffer * _vertexArrayObject;

public:


	/**
	*objects need to be imput from the storage in sceneNode
	*these objects else will have to be destroyed manually
	**/
	Model(SceneNode* sceneNode,VertexBufferObjectWithSubData* vertexBufferObject,VertexElementBuffer* vertexArrayObject,Source* vertexSource, Source* Fragmentsource);
	virtual ~Model(void);

	/**
	*draws the model with the given shader
	**/
	virtual void Draw(Matrix4f transform, Matrix4f view);
	/**
	*draws the model without any from of shading
	**/
	virtual void DepthDraw(Matrix4f transform, Matrix4f view);
};

#endif