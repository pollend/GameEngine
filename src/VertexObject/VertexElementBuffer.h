#ifndef _VERTEX_ARRAY_OBJECT_H_
#define _VERTEX_ARRAY_OBJECT_H_

#include "VertexObject.h"
#include <GL/glew.h>

class VertexElementBuffer : public VertexObject
{
private:
	int _numberOfIndecies;
	GLushort * _data;
public:

	/**
	*declares a vertex array of indecies
	*
	**/
	VertexElementBuffer(const GLushort data[], int size) ;
	~VertexElementBuffer(void);

	/**
	*binders the vertex array Object
	**/
	virtual void Bind();

	/**
	*returns the number of indecies
	**/
	int GetNumberOfIndecies();
};

#endif