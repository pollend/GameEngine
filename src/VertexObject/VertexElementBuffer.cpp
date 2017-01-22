#include "VertexObject/VertexElementBuffer.h"
#include <stdlib.h>


VertexElementBuffer::VertexElementBuffer(const GLushort data[], int size) : VertexObject()
{

	_numberOfIndecies = size;
	_data = (GLushort*)malloc(sizeof(GLushort) * size);
	for(int i = 0; i < size; i++)
	{
		_data[i] = data[i];
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLushort) * size,_data,GL_STATIC_DRAW);
}


void VertexElementBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_vbo);
}

void VertexElementBuffer::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}

int VertexElementBuffer::GetNumberOfIndecies()
{
	return _numberOfIndecies;
}



VertexElementBuffer::~VertexElementBuffer(void)
{
	free( _data);
}
