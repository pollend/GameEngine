#include "VertexObject/VertexBufferObjectWithSubData.h"
#include <boost/log/trivial.hpp>

VertexBufferObjectWithSubData::SubData::SubData(GLfloat data[],int size,int vectorType)
{
		_data = new GLfloat[size];
		 for(int x =0; x < size; x++)
		 {
			 _data[x] = data[x];
		 }

		 _size = size * sizeof(GLfloat);
		 _vectorType = vectorType;
		  _listedType ="";
}
VertexBufferObjectWithSubData::SubData::SubData(Vector2f data[],int size)
{
		_data = new GLfloat[size* 2];
		 for(int x =0; x < size; x++)
		 {
			 _data[(x * 2)+ 0] = data[x].x();
			 _data[(x * 2)+ 1] = data[x].y();
		 }
		 _size = size * 2* sizeof(GLfloat);
		 _vectorType = 2;
		  _listedType ="";
}
VertexBufferObjectWithSubData::SubData::SubData(Vector3f data[],int size)
{
		_data = new GLfloat[size* 3];
		 for(int x =0; x < size; x++)
		 {
			 _data[(x * 3)+ 0] = data[x].x();
			 _data[(x * 3)+ 1] = data[x].y();
			 _data[(x * 3)+ 2] = data[x].z();
		 }
		 _size = size * 3* sizeof(GLfloat);
		 _vectorType = 3;
		  _listedType ="";
}
VertexBufferObjectWithSubData::SubData::SubData(Vector4f data[],int size)
{
		_data = new GLfloat[size* 4];
		 for(int x =0; x < size; x++)
		 {
			 _data[(x * 4)+ 0] = data[x].x();
			 _data[(x * 4)+ 1] = data[x].y();
			 _data[(x * 4)+ 2] = data[x].z();
			 _data[(x * 4)+ 3] = data[x].w();
		 }
		 _size = size * 4* sizeof(GLfloat);
		 _vectorType = 4;
		 _listedType ="";
	
}

VertexBufferObjectWithSubData::SubData::SubData(GLfloat data[],int size,int vectorType,std::string listed)
{
	_data = new GLfloat[size];
	for(int x =0; x < size; x++)
	{
		_data[x] = data[x];
	}

	_size = size * sizeof(GLfloat);
	_vectorType = vectorType;
	
	_listedType = listed;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector2f data[],int size,std::string listed)
{
	_data = new GLfloat[size* 2];
	for(int x =0; x < size; x++)
	{
		_data[(x * 2)+ 0] = data[x].x();
		_data[(x * 2)+ 1] = data[x].y();
	}
	_size = size * 2* sizeof(GLfloat);
	_vectorType = 2;

	_listedType = listed;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector3f data[],int size,std::string listed)
{
	_data = new GLfloat[size* 3];
	for(int x =0; x < size; x++)
	{
		_data[(x * 3)+ 0] = data[x].x();
		_data[(x * 3)+ 1] = data[x].y();
		_data[(x * 3)+ 2] = data[x].z();
	}
	_size = size * 3* sizeof(GLfloat);
	_vectorType = 3;
	_listedType = listed;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector4f data[],int size,std::string listed)
{
	_data = new GLfloat[size* 4];
	for(int x =0; x < size; x++)
	{
		_data[(x * 4)+ 0] = data[x].x();
		_data[(x * 4)+ 1] = data[x].y();
		_data[(x * 4)+ 2] = data[x].z();
		_data[(x * 4)+ 3] = data[x].w();
	}
	_size = size * 4* sizeof(GLfloat);
	_vectorType = 4;
	_listedType = listed;
}


VertexBufferObjectWithSubData::SubData::~SubData()
{
	delete[] _data;
}

int VertexBufferObjectWithSubData::SubData::GetVectorType()
{
	return _vectorType;
}


GLsizeiptr VertexBufferObjectWithSubData::SubData::GetSize()
{
	return _size;
}


GLfloat* VertexBufferObjectWithSubData::SubData::GetData()
{
	return _data;
}

void VertexBufferObjectWithSubData::SubData::SetListed(std::string type)
{
	_listedType = type;
}

std::string VertexBufferObjectWithSubData::SubData::GetListedType()
{
	return _listedType;
}



VertexBufferObjectWithSubData::VertexBufferObjectWithSubData(void) : VertexObject()
{
	_data = std::vector<SubData*>();
}


VertexBufferObjectWithSubData::~VertexBufferObjectWithSubData(void)
{
	for(int i = 0; i < _data.size(); i++)
	{
		delete(_data[i]);
	}
}

void VertexBufferObjectWithSubData::IntalizeBuffer()
{

	GLsizeiptr lsize = 0;
	for(int x =0; x < _data.size(); x++)
	{
		lsize += _data[x]->GetSize();
	}
	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER,_vbo);
	glBufferData(GL_ARRAY_BUFFER,lsize,NULL, GL_STATIC_DRAW );

	GLsizeiptr loffset = 0;
	for(int x =0; x < _data.size(); x++)
	{
		glBufferSubData(GL_ARRAY_BUFFER,loffset,_data[x]->GetSize(),_data[x]->GetData());
		loffset += _data[x]->GetSize();
	
	}

	//setup VAO
	loffset = 0;
	for(int x =0; x < _data.size(); x++)
	{
		glEnableVertexAttribArray(x);
		glVertexAttribPointer(x,_data[x]->GetVectorType(),GL_FLOAT,GL_FALSE,0,(void*)loffset);
		loffset += _data[x]->GetSize();
	}
	glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VertexBufferObjectWithSubData::AddSubData(SubData* subData)
{
	_data.push_back(subData);
}

void VertexBufferObjectWithSubData::Bind()
{
	glBindVertexArray(_vao);
}


void VertexBufferObjectWithSubData::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER,0);

}

int VertexBufferObjectWithSubData::GetSize()
{
	return _data.size();
}

VertexBufferObjectWithSubData::SubData* VertexBufferObjectWithSubData::operator [] (const int index)
{
	return _data[index];
}