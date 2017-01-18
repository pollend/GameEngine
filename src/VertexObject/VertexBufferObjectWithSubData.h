#include <GL/glew.h>
#include "VertexObject.h"
#include <vector>
#include "VertexObject.h"
#include <string>
#include <Eigen/Dense>


#ifndef _VERTEX_BUFFER_OBJECT_WITH_SUB_DATA_H_
#define _VERTEX_BUFFER_OBJECT_WITH_SUB_DATA_H_

#define VERTEX "VERTEX"
#define NORMALS "NORMALS"
#define TEX_COORDS "TEX_COORDS"

using Eigen::Vector2f;
using Eigen::Vector3f;
using Eigen::Vector4f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;


class VertexBufferObjectWithSubData : public VertexObject
{
public:
	class SubData
	{
		private:
			int _vectorType;
			GLfloat * _data;
			GLsizeiptr _size;
			std::string _listedType;
		public:
			/**
			*
			**/
			SubData(GLfloat data[],int size,int vectorType);
			SubData(Vector2f data[],int size);
			SubData(Vector3f data[],int size);
			SubData(Vector4f data[],int size);

			SubData(GLfloat data[],int size,int vectorType,std::string listed);
			SubData(Vector2f data[],int size,std::string listed);
			SubData(Vector3f data[],int size,std::string listed);
			SubData(Vector4f data[],int size,std::string listed);

			~SubData();

			GLfloat* GetData();

			/**
			*returns the vector type
			**/
			int GetVectorType();
			/**
			 *get the total size
			 **/
			 
			/**
			 *Get the size of data sotred in the sub-data element
			 **/
			GLsizeiptr GetSize();

			/**
			 *get the stored size of the subdata element
			 ***/
			void SetListed(std::string type);

			/**
			 *get what the subdata is listed as
			 **/
			std::string GetListedType();

	};

private:
	std::vector<SubData*> _data;

public:

	
	VertexBufferObjectWithSubData(void);
	~VertexBufferObjectWithSubData(void);
	
	/**
	 *adds a subdata element
	 **/
	void AddSubData(SubData* subData);
	
	/**
	 *retrieves the size of the entire set
	 **/
	int GetSize();

	/**
	 *retrieves the index of the subdata location
	 **/
	SubData* operator [] (const int index);

	/**
	 *intalize the buffer object
	 **/
	void IntalizeBuffer();

	/**
	 *binds the buffer object
	 **/
	virtual void Bind();
};

#endif