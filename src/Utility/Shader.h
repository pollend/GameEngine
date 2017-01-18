#ifndef _SHADER_H_
#define _SHADER_H_


#include <GL/glew.h>
#include <map>
#include <string>
#include <Utility/Vector/Vector2.h>
#include <Utility/Vector/Vector3.h>
#include <Utility/Vector/Vector4.h>
#include <Utility/Matrix/Matrix4x4.h>
#include "Source.h"
#include "Texture.h"

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
	static void Unbind();

	void SetAttrib(int index, const GLchar* attrib);

	void SetUniform1(const GLchar* UniformID, GLint value);
	void SetUniform1(const GLchar* UniformID,GLint value[]);

	void SetUniform1(const GLchar* UniformID, GLfloat value);
	void SetUniform1(const GLchar* UniformID,const GLfloat value[]);

	void SetUniform2(const GLchar* UniformID, Vector2 value);
	void SetUniform2(const GLchar* UniformID, Vector2 value[]);

	void SetUniform3(const GLchar* UniformID, Vector3 value);
	void SetUniform3(const GLchar* UniformID, Vector3 value[]);

	void SetUniform4(const GLchar* UniformID, Vector4 value);
	void SetUniform4(const GLchar* UniformID, Vector4 value[]);

	void SetMatrix4x4(const GLchar* UniformID,Matrix4x4 m);
	void SetMatrix4x4(const GLchar* UniformID,Matrix4x4 m[]);

	void SetTexture(const GLchar* UniformID,Texture* texture,int index);
};

#endif