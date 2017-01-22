#include <GL/glew.h>

#ifndef _VERTEX_OBJECT_H
#define _VERTEX_OBJECT_H

class VertexObject
{
protected:

	GLuint _vbo;
	GLuint _vao;
public:
	VertexObject(void);
	virtual ~VertexObject(void);

	virtual void Bind() = 0;

};

#endif