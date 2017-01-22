#ifndef _RENDERER_H_
#define _RENDERER_H_


#include <Node/Node.h>
#include <Node/SceneNode.h>
#include "Render/RenderingProcedure/RenderingProcedure.h"

class SceneNode;
class Framebuffer;
class Renderer
{


public:
	void Clear();
	void DrawNode(Node* node,Camera* camera);
	void ChangeRenderTarget(Framebuffer* framebuffer);
	void UnbindRenderTarget();
	Renderer(void);
	~Renderer(void);
};

#endif