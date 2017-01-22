
#ifndef _Sprite_H_
#define _Sprite_H_

#include "RenderObject.h"
#define SPRITE_VERTICIES_SIZE 12
#define SPRITE_VERTICIES {0,0,0, 1,0,0, 0,1,0, 1,1,0 }

#define SPRITE_INDECIES_SIZE 6
#define SPRITE_INDECIES {2,0,1,2,1,3}

#define SPRITE_VERTEX_SHADER "\
attribute  vec3 in_Verts; \
attribute float in_Index; \
uniform mat4 in_Transform; \
uniform mat4 in_View; \
uniform vec2 in_Clipping_Position; \
uniform vec2 in_Clipping_Size; \
varying vec2 p_TexCoords; \
void main(void)\
{ \
	gl_Position =in_View *  in_Transform * vec4(in_Verts,1.0); \
	if(int(in_Index) == 0) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x ,in_Clipping_Position.y + in_Clipping_Size.y); \
	} \
	else if(int(in_Index) == 1) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x+in_Clipping_Size.x,in_Clipping_Position.y + in_Clipping_Size.y); \
	} \
	else if(int(in_Index) == 2) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x,in_Clipping_Position.y); \
	} \
	else if(int(in_Index) == 3) \
	{ \
		p_TexCoords = vec2(in_Clipping_Position.x+ in_Clipping_Size.x,in_Clipping_Position.y); \
	} \
}"
#define SPRITE_FRAGMENT_SHADER "\
varying vec2 p_TexCoords; \
uniform sampler2D in_BaseImage;\
\
void main()\
{\
gl_FragColor = texture2D(in_BaseImage,p_TexCoords);\
}"
#define SPRITE "SMOKE_SPRITE"
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::Vector2f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;

class VertexElementBuffer;
class VertexBufferObjectWithSubData;
class Sprite : public RenderObject
{
private:
	VertexElementBuffer * mVertexArrayObject;
	SceneNode * _sceneNode;

	Source *_vertexSource;
	Source *_fragmentSource;

	VertexElementBuffer*_vertexElementbuffer;
	VertexBufferObjectWithSubData* _vertexObject;

	//sprite intalization
	void _initialize(SceneNode * sceneNode);
public:
	VertexBufferObjectWithSubData * mVertexSubData;
	/**
	*create a spirte object with custom fragment shader
	*textures will have to be done manually in shader
	**/
	Sprite(SceneNode * sceneNode,Source * fragmentShader);
	/**
	*
	**/
	Sprite(SceneNode * sceneNode,Texture * texture);
	~Sprite(void);

	/**
	*sets the clipping rectangle for the sprite
	*ranged from 0 to 1 based on tex coords
	**/
	void SetClippingRectangle(Vector2f pos, Vector2f size);

	virtual void Draw(Matrix4f transform, Matrix4f view);
	virtual void DepthDraw(Matrix4f transform, Matrix4f view);

};

#endif
