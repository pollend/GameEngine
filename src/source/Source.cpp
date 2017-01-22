#include "Utility/Source.h"
#include <fstream>
#include <cstring>
#include <boost/log/trivial.hpp>

Source::Source(const char* source,GLenum Type)
{
	_type = Type;
	_source = glCreateShader(Type);
	_compile(source);

}
Source::Source(const char* path)
{
    BOOST_LOG_TRIVIAL(trace) << "loading shader file:" <<  path;

    if(path[ strlen(path) -1] == 's' && path[ strlen(path) -2] == 'v')
    {
        _type = GL_VERTEX_SHADER;
        _source = glCreateShader(GL_VERTEX_SHADER);
    }
    else if(path[ strlen(path) -2] == 'f' && path[ strlen(path) -1] == 's')
    {
        _type = GL_FRAGMENT_SHADER;
        _source = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else
    {
        BOOST_LOG_TRIVIAL(error) << "invalid shader file type:" <<  path;

    }


    std::ifstream file(path, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[size+1]();
    if (!file.read(buffer, size))
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to open:" << path;
        file.close();
        delete(buffer);
        return;
    }
    buffer[size] = '\0';
    if(!_compile(buffer))
    {
        BOOST_LOG_TRIVIAL(error) << "Failed to compile shader: " << path;
    }
    delete(buffer);

}

GLuint Source::GetSourceID()
{
	return _source;
}

GLenum Source::GetType()
{
	return _type;
}

bool Source::_compile(const char* source)
{
	if(_source)
	{
		glShaderSource(_source,1,&source,NULL);
		glCompileShader(_source);
		GLint lcompile = 0;
		glGetShaderiv(_source, GL_COMPILE_STATUS, &lcompile);
		if (!lcompile) {
			GLint linfoLen = 0;
			 glGetShaderiv(_source, GL_INFO_LOG_LENGTH, &linfoLen);
			 if (linfoLen) {
				char* lbuffer = (char*) malloc(linfoLen);
				if (lbuffer) {
					glGetShaderInfoLog(_source, linfoLen, NULL, lbuffer);
                    BOOST_LOG_TRIVIAL(error) << "could not compile shader: " << source;
                    BOOST_LOG_TRIVIAL(error) << lbuffer;
					free(lbuffer);
				}
				glDeleteShader(_source);
				_source = 0;
				return false;
			 }

		}
	}
	return true;
}

Source::~Source(void)
{

		glDeleteShader(_source);
}
