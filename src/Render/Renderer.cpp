#include "Render/Renderer.h"
#include "Node/ObjectNode.h"


Renderer::Renderer(void)
{

}


Renderer::~Renderer(void)
{

}


//
//void Renderer::Draw(SceneNode* scene)
//{
//	_matrixStack.Push(scene->mMainCamera->GetMatrix());
//	DrawNode(scene->mRootSceneNode,scene);
//	_matrixStack.Pop();
//	//DrawNode(scene->mRootOverlayNode);
//
//}

void Renderer::DrawNode(Node* node,Camera* camera)
{
	if(node->GetType() == "object_node")
	{

		static_cast<ObjectNode*>((node))->Draw(node->GetTransformation(),camera->GetViewMatrix());
	}
}
// not rendering from top down due to being inflexible
//void Renderer::DrawNode(Node * n,SceneNode *scene)
//{
//	for(std::list<Node*>::iterator iter = n->GetChildren()->begin(); iter !=  n->GetChildren()->end();++iter)
//	{
//		_matrixStack.Push((*iter)->GetMatrix());
//		if((*iter)->GetType() == "object_node")
//		{
//			static_cast<ObjectNode*>((*iter))->Draw(_matrixStack.GetTransformMatrix(),scene->mMainCamera->GetViewMatrix());
//		}
//		DrawNode((*iter),scene);
//		_matrixStack.Pop();
//	}
//}