#ifndef _RENDERER_H_
#define _RENDERER_H_

class SceneNode;

#include <Node/Node.h>
#include <Node/SceneNode.h>
#include "Utility/Matrix/MatrixStack.h"

class Renderer
{
private:
	/**
	*a stack used to get the transform as the system progresses down the tree
	**/
	MatrixStack _matrixStack;
	
	/**
	*used to progress down the tree
	**/
	void DrawNode(Node * n,SceneNode *scene);
public:
	/**
	*draws the scene
	**/
	void Draw(SceneNode *scene);

	Renderer(void);
	~Renderer(void);
};

#endif