#include "Node/SceneNode.h"
#include "SharedNodeInfo.h"


SceneNode::RootNode::RootNode(SceneNode * sceneNode,SharedNodeInfo* sharedNodeInfo, std::string ID) : Node(ID) 
{
	_sceneNode = sceneNode;
	_sharedNodeInfo = sharedNodeInfo;

}
std::string SceneNode::RootNode::GetType()
{
	return "root_node";
}

SceneNode::SceneNode(SmokeEngine* smokeEngine,Camera * camera)
{
	_isLoaded = false;

	_sharedNodeInfo = new SharedNodeInfo();

	mSmokeEngine = smokeEngine;

	mRootSceneNode = new RootNode(this,_sharedNodeInfo,"ROOT_SCENE");
	mRootOverlayNode  = new RootNode(this,_sharedNodeInfo,"ROOT_OVERLAY");
	mMainCamera = camera;
}
void SceneNode::Load()
{
	_isLoaded = true;
}

void SceneNode::UnLoad()
{
	_isLoaded = false;
}


bool SceneNode::IsLoad()
{
	return _isLoaded;
}

SceneNode::~SceneNode(void)
{
	delete(mRootSceneNode);
	delete(mRootOverlayNode);
	delete(_sharedNodeInfo);
}
