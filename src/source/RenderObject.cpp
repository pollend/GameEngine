#include "Render/RenderObject.h"
#include "Utility/Shader.h"
#include "Node/SceneNode.h"
#include "Utility/Source.h"
#include "SmokeEngine.h"

RenderObject::RenderObject(SceneNode * sceneNode)
{
	mShader = new Shader();

	_depthShader.AttachSource(new Source(DEPTH_FRAGMENT_SHADER,GL_FRAGMENT_SHADER));
	_depthShader.AttachSource(new Source(DEPTH_VERTEX_SHADER,GL_VERTEX_SHADER));
	

}


RenderObject::~RenderObject(void)
{

}
