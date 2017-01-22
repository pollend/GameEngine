#include "VertexObject/VertexObject.h"

VertexObject::VertexObject(void)
{
	glGenBuffers(1,&_vbo);
	glGenVertexArrays(1,&_vao);
}

VertexObject::~VertexObject(void)
{
	glDeleteBuffers(1,&_vbo);
	glDeleteVertexArrays(1,&_vao);
}
