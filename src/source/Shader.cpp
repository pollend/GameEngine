#include "Utility/Shader.h"
#include "Utility/Source.h"
#include "Utility/Texture.h"
#include <boost/log/trivial.hpp>

Shader::Shader(void)
{
	_shaderProgram = glCreateProgram();

	_textures = std::map<int,GLuint>();
}

void Shader::_useShader()
{
	//if(_shaderProgram != Shader::ActiveProgram ) {
		glUseProgram(_shaderProgram);
		//Shader::ActiveProgram = _shaderProgram;
	//}
}

Shader::~Shader(void)
{
	glDeleteProgram(_shaderProgram);
}

void Shader::AttachSource(Source* source)
{
	glAttachShader(_shaderProgram,source->GetSourceID());
}

void Shader::IntalizeShader()
{
	glLinkProgram(_shaderProgram);

	GLint lcompile = 0;
	glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &lcompile);
	if (!lcompile) {
		GLint linfoLen = 0;
		glGetProgramiv(_shaderProgram, GL_INFO_LOG_LENGTH, &linfoLen);
		if (linfoLen) {
			char* lbuffer = (char*) malloc(linfoLen);
			if (lbuffer) {
				glGetProgramInfoLog(_shaderProgram, linfoLen, NULL, lbuffer);
				BOOST_LOG_TRIVIAL(error) << "could not compile shader: " << _shaderProgram;
				BOOST_LOG_TRIVIAL(error) << lbuffer;
				free(lbuffer);
			}
			glDeleteProgram(_shaderProgram);
		}

	}
}

void Shader::SetAttrib(int index, const GLchar* attrib)
{
	//_useShader();
	glBindAttribLocation(_shaderProgram,index,attrib);
}

//UNIFORM 1
void Shader::SetUniform1(const GLchar* UniformID, GLint value)
{
	_useShader();
	glUniform1i(glGetUniformLocation(_shaderProgram,UniformID),value);
}



void Shader::SetUniform1(const GLchar* UniformID, GLfloat value)
{
	_useShader();
	glUniform1f(glGetUniformLocation(_shaderProgram,UniformID),value);
}


//uniform 2
void Shader::SetUniform2(const GLchar* UniformID, Vector2f value)
{
	_useShader();
	glUniform2f(glGetUniformLocation(_shaderProgram,UniformID),value.x(),value.y());

}

//uniform 3
void Shader::SetUniform3(const GLchar* UniformID, Vector3f value)
{
	_useShader();
	glUniform3f(glGetUniformLocation(_shaderProgram,UniformID),value.x(),value.y(),value.z());
}

//uniform 4
void Shader::SetUniform4(const GLchar* UniformID, Vector4f value)
{
	_useShader();
	glUniform4f(glGetUniformLocation(_shaderProgram,UniformID),value.x(),value.y(),value.z(),value.w());
}

void Shader::SetTexture(const GLchar* UniformID,Texture* texture,int index)
{
	_useShader();
	if(_textures.count(index))
	{
		_textures[index] = texture->GetResourceID();
	}
	else
	{
		_textures.insert(std::pair<int,GLuint>(index,texture->GetResourceID()) );
	}
	glUniform1i(glGetUniformLocation(_shaderProgram,UniformID),index);
}

void Shader::SetMatrix4x4(const GLchar* UniformID, Matrix4f m)
{

	GLfloat lvalue[16] = {m(0,0), m(0,1), m(0,2), m(0,3),
						  m(1,0), m(1,1), m(1,2), m(1,3),
						  m(2,0), m(2,1), m(2,2), m(2,3),
						  m(3,0), m(3,1), m(3,2), m(3,3)};
	_useShader();
	glUniformMatrix4fv(glGetUniformLocation(_shaderProgram,UniformID),1,false,lvalue);

}


void Shader::BindShader()
{
	_useShader();
	for(std::map<int,GLuint>::iterator iter = _textures.begin(); iter != _textures.end(); iter++)
	{
		glActiveTexture(GL_TEXTURE0 + iter->first);
		glBindTexture(GL_TEXTURE_2D,iter->second);
	}
}

void Shader::Unbind()
{
	glUseProgram(0);
	//Shader::ActiveProgram = 0;

}


int Shader::ActiveProgram = 0;