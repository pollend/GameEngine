#ifndef _RENDERER_H_
#define _RENDERER_H_


#include <Node/Node.h>
#include <Node/SceneNode.h>
#include "Utility/Matrix/MatrixStack.h"
#include "Render/RenderingProcedure/RenderingProcedure.h"

class SceneNode;
class Framebuffer;
class Renderer
{
private:
	/**
	*a stack used to get the transform as the system progresses down the tree
	**/
	MatrixStack _matrixStack;

public:
	void Clear();
	void DrawNode(Node* node,Camera* camera);
	void ChangeRenderTarget(Framebuffer* framebuffer);
	void UnbindRenderTarget();
	Renderer(void);
	~Renderer(void);
};

#endif