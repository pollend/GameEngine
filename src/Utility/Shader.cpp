#include "Utility/Shader.h"
#include "Utility/Source.h"
#include "Utility/Texture.h"

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
	glUseProgram(_shaderProgram);
}

void Shader::SetAttrib(int index, const GLchar* attrib)
{
	glBindAttribLocation(_shaderProgram,index,attrib);
}

//UNIFORM 1
void Shader::SetUniform1(const GLchar* UniformID, GLint value)
{
	_useShader();
	glUniform1i(glGetUniformLocation(_shaderProgram,UniformID),value);
}

void Shader::SetUniform1(const GLchar* UniformID,GLint value[])
{
	_useShader();
	glUniform1iv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),value);
}

void Shader::SetUniform1(const GLchar* UniformID, GLfloat value)
{
	_useShader();
	glUniform1f(glGetUniformLocation(_shaderProgram,UniformID),value);
}

void Shader::SetUniform1(const GLchar* UniformID,const GLfloat value[])
{
	_useShader();
	glUniform1fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),value);
}

//uniform 2
void Shader::SetUniform2(const GLchar* UniformID, Vector2f value)
{
	_useShader();
	glUniform2f(glGetUniformLocation(_shaderProgram,UniformID),value.x(),value.y());

}

void Shader::SetUniform2(const GLchar* UniformID, Vector2f value[])
{
	GLfloat lvalue[sizeof(value) *2];
	for(int x = 0; x < sizeof(value) ; x++)
	{
		lvalue[(x*2)] = value[x].x();
		lvalue[(x*2)+1] = value[x].y();
	}
	_useShader();
	glUniform2fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),lvalue);
}

//uniform 3
void Shader::SetUniform3(const GLchar* UniformID, Vector3f value)
{
	_useShader();
	glUniform3f(glGetUniformLocation(_shaderProgram,UniformID),value.x(),value.y(),value.z());
}

void Shader::SetUniform3(const GLchar* UniformID, Vector3f value[])
{
	GLfloat lvalue[sizeof(value) *3];
	for(int x = 0; x < sizeof(value) ; x++)
	{
		lvalue[(x*3)] = value[x].x();
		lvalue[(x*3)+1] = value[x].y();
		lvalue[(x*3)+2] = value[x].z();
	}
	_useShader();
	glUniform3fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),lvalue);

}

//uniform 4
void Shader::SetUniform4(const GLchar* UniformID, Vector4f value)
{
	_useShader();
	glUniform4f(glGetUniformLocation(_shaderProgram,UniformID),value.x(),value.y(),value.z(),value.w());
}

void Shader::SetUniform4(const GLchar* UniformID, Vector4f value[])
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
	glUniform4fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),lvalue);

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
	GLfloat lvalue[16];
//	lvalue[0] = m.m11;
//	lvalue[1] = m.m21;
//	lvalue[2] = m.m31;
//	lvalue[3] = m.m41;
//
//	lvalue[4] = m.m12;
//	lvalue[5] = m.m22;
//	lvalue[6] = m.m32;
//	lvalue[7] = m.m42;
//
//	lvalue[8] = m.m13;
//	lvalue[9] = m.m23;
//	lvalue[10] = m.m33;
//	lvalue[11] = m.m43;
//
//	lvalue[12] = m.m14;
//	lvalue[13] = m.m24;
//	lvalue[14] = m.m34;
//	lvalue[15] = m.m44;

	lvalue[0] = m(0,0);
	lvalue[1] = m(0,1);
	lvalue[2] = m(0,2);
	lvalue[3] = m(0,3);

	lvalue[4] = m(1,0);
	lvalue[5] = m(1,1);
	lvalue[6] = m(1,2);
	lvalue[7] = m(1,3);

	lvalue[8] = m(2,0);
	lvalue[9] = m(2,1);
	lvalue[10]= m(2,2);
	lvalue[11]= m(2,3);

	lvalue[12] = m(3,0);
	lvalue[13] = m(3,1);
	lvalue[14] = m(3,2);
	lvalue[15] = m(3,3);

	_useShader();
	glUniformMatrix4fv(glGetUniformLocation(_shaderProgram,UniformID),1,false,lvalue);

}

void Shader::SetMatrix4x4(const GLchar* UniformID,Matrix4f m[])
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
	glUniform4fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(m),lvalue);


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