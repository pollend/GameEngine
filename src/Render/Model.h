#ifndef _MODEL_H_
#define _MODEL_H_

#include <VertexObject/VertexBufferObjectWithSubData.h>
#include <VertexObject/VertexElementBuffer.h>
#include "Render/RenderObject.h"


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
	virtual void Draw(Matrix4x4 transform, Matrix4x4 view);
	/**
	*draws the model without any from of shading
	**/
	virtual void DepthDraw(Matrix4x4 transform, Matrix4x4 view);
};

#endif