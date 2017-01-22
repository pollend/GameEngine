#ifndef _SHADER_H_
#define _SHADER_H_


#include <GL/glew.h>
#include <map>
#include <string>
#include "Source.h"
#include "Texture.h"

#include <Eigen/Dense>

using Eigen::Vector2f;
using Eigen::Vector3f;
using Eigen::Vector4f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;

class Shader
{
private:
	GLuint _shaderProgram;
	std::map<int,GLuint> _textures;
	void _useShader();

public:
	static int ActiveProgram;

	Shader(void);
	~Shader(void);

	void AttachSource(Source* source);
	void IntalizeShader();

	void BindShader();
	void UnbindShader();
	static void Unbind();

	void SetAttrib(int index, const GLchar* attrib);

	void SetUniform1(const GLchar* UniformID, GLint value);
	template <long unsigned size>
	void SetUniform1(const GLchar* UniformID,GLint value[size])
	{
		_useShader();
		glUniform1iv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(GLint)*size,value);
	}

	void SetUniform1(const GLchar* UniformID, GLfloat value);
	template <long unsigned size>
	void SetUniform1(const GLchar* UniformID, GLfloat value[size])
	{
		_useShader();
		glUniform1fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(GLfloat)*size,value);
	}
	void SetUniform2(const GLchar* UniformID, Vector2f value);

	template <long unsigned size>
	void SetUniform2(const GLchar* UniformID, Vector2f value[size])
	{
		GLfloat lvalue[sizeof(value) *2];
		for(int x = 0; x < sizeof(value) ; x++)
		{
			lvalue[(x*2)] = value[x].x();
			lvalue[(x*2)+1] = value[x].y();
		}
		_useShader();
		glUniform2fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(GLfloat)*size,lvalue);
	}


	void SetUniform3(const GLchar* UniformID, Vector3f value);
	template <long unsigned size>
	void SetUniform3(const GLchar* UniformID, Vector3f value[])
	{
		GLfloat lvalue[sizeof(value) *3];
		for(int x = 0; x < sizeof(value) ; x++)
		{
			lvalue[(x*3)] = value[x].x();
			lvalue[(x*3)+1] = value[x].y();
			lvalue[(x*3)+2] = value[x].z();
		}
		_useShader();
		glUniform3fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(GLfloat)*size,lvalue);

	}

	void SetUniform4(const GLchar* UniformID, Vector4f value);
	template <long unsigned size>
	void SetUniform4(const GLchar* UniformID, Vector4f value[])
	{
		GLfloat lvalue[sizeof(value) *4];
		for(int x = 0; x < sizeof(value) ; x++)
		{
			lvalue[(x*4)] = value[x].x();
			lvalue[(x*4)+1] = value[x].y();
			lvalue[(x*4)+2] = value[x].z();
			lvalue[(x*4)+4] = value[x].w();
		}
		_useShader();
		glUniform4fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(GLfloat)*size,lvalue);

	}

	void SetMatrix4x4(const GLchar* UniformID,Matrix4f m);
	template <long unsigned size>
	void SetMatrix4x4(const GLchar* UniformID,Matrix4f m[])
	{
		GLfloat lvalue[sizeof(m) *16];
		for(int x = 0; x < sizeof(m) ; x++)
		{

			lvalue[(x*16)]   = m[x](0,0);
			lvalue[(x*16)+1] = m[x](0,1);
			lvalue[(x*16)+2] = m[x](0,2);
			lvalue[(x*16)+3] = m[x](0,3);

			lvalue[(x*16)+4] = m[x](1,0);
			lvalue[(x*16)+5] = m[x](1,1);
			lvalue[(x*16)+6] = m[x](1,2);
			lvalue[(x*16)+7] = m[x](1,3);

			lvalue[(x*16)+8] = m[x](2,0);
			lvalue[(x*16)+9] = m[x](2,1);
			lvalue[(x*16)+10] = m[x](2,2);
			lvalue[(x*16)+11] = m[x](2,3);

			lvalue[(x*16)+12] = m[x](3,0);
			lvalue[(x*16)+13] = m[x](3,1);
			lvalue[(x*16)+14] = m[x](3,2);
			lvalue[(x*16)+15] = m[x](3,3);
		}
		_useShader();
		glUniform4fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(GLfloat)*size*16,lvalue);


	}

	void SetTexture(const GLchar* UniformID,Texture* texture,int index);
};

#endif