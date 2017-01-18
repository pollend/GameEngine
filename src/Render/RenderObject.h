#ifndef _RENDER_OBJECT_H
#define _RENDER_OBJECT_H

#include <GL/glew.h>
#include <Utility/Matrix/Matrix4x4.h>
#include <Utility/Shader.h>
#include <Node/SceneNode.h>

#define DEPTH_VERTEX_SHADER  "\
 uniform mat4 in_Transform; \
 uniform mat4 in_View; \
 attribute vec3 in_Verts; \
 void main(void) \
 { \
	gl_Position = in_View * in_Transform * vec4(in_Verts.xyz,1.0); \
 }"
#define DEPTH_FRAGMENT_SHADER  "\
void main() \
 { \
	 gl_FragColor = vec4(0,0,0,1); \
 }"
#define DEPTH_SHADER "SMOKE_DEPTH_SHADER"

class RenderObject
{
private:
	Shader * _depthShader;
public:
	Shader * mShader;
	
	RenderObject(SceneNode * sceneNode);
	~RenderObject(void);

	 virtual void Draw(Matrix4x4 transform, Matrix4x4 view) = 0;
	 virtual void DepthDraw(Matrix4x4 transform, Matrix4x4 view) = 0;
};

#endif

