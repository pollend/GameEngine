#ifndef _SOURCE_H_
#define _SOURCE_H_

#include <string>
#include <GL/glew.h>

class Source
{
private:
	GLuint _source;
	char* _data;
	GLenum _type;
	bool _compile(const char* source);
public:
	/**
	*loads the string as source
	* GL_VERTEX_SHADER & GL_FRAGMENT_SHADER
	**/
	Source(const char* source,GLenum Type);
	/**
	*loads the file from the asset folder
	* ending is either .vs or .fs
	*.vs is vertex shader and .fs is fragment shader
	**/
	Source(const char* path);
	//returns the shader type - GL_VERTEX_SHADER & GL_FRAGMENT_SHADER
	GLenum GetType();
	/**
	*gets the source id
	**/
	GLuint GetSourceID();
	~Source(void);
};

#endif
