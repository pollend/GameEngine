#ifndef _WAVE_FRONT_LOADER_H_
#define _WAVE_FRONT_LOADER_H_

#include <string>
#include <vector>
#include <VertexObject/VertexArrayObject.h>
#include <VertexObject/VertexBufferObjectWithSubData.h>


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
	static VertexArrayObject* Load(const char* file, VertexBufferObjectWithSubData * vertexBufferObjectWithSubData);
};

#endif