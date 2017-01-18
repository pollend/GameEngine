#ifndef _VERTEX_ARRAY_OBJECT_H_
#define _VERTEX_ARRAY_OBJECT_H_

#include "VertexObject.h"
#include <GL/glew.h>

class VertexArrayObject : public VertexObject
{
private:
	int _numberOfIndecies;
	GLushort * _data;
public:

	/**
	*declares a vertex array of indecies
	*
	**/
	VertexArrayObject(const GLushort data[], int size) ;
	~VertexArrayObject(void);

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