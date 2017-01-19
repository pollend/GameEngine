#ifndef _WAVE_FRONT_LOADER_H_
#define _WAVE_FRONT_LOADER_H_

#include <string>
#include <vector>
#include <VertexObject/VertexElementBuffer.h>
#include <VertexObject/VertexBufferObjectWithSubData.h>
#include <Eigen/Dense>


using Eigen::Matrix4f;
using Eigen::Matrix3f;
using Eigen::Vector3f;
using Eigen::Vector2f;
using Eigen::Quaternionf;

class WaveFrontLoad
{
private:
	/**
	*splits the string out of a float
	**/
	 static std::vector<float> _splitFloat(std::string str,std::string character);
	 /**
	 *splits intiger values out of a string
	 **/
	 static std::vector<int> _splitInt(std::string str,std::string character);
public:
	/**
	*loads the wavefront file and stores the values within the subdata object and array object
	**/
	static VertexElementBuffer* Load(const char* file, VertexBufferObjectWithSubData * vertexBufferObjectWithSubData);
};

#endif