#pragma once
#include <GL/glew.h>
class VertexObject
{
protected:

	GLuint* _id;
public:
	VertexObject(void);
	virtual ~VertexObject(void);

	virtual void Bind() = 0;

};
