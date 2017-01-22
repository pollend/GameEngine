#include "Node/SceneNode.h"
#include "Node/SharedNodeInfo.h"


SceneNode::RootNode::RootNode(SharedNodeInfo* sharedNodeInfo, std::string ID) : Node(ID)
{
	_sharedNodeInfo = sharedNodeInfo;

}
std::string SceneNode::RootNode::GetType()
{
	return "root_node";
}

SceneNode::SceneNode(SmokeEngine* smokeEngine)
{
	_isLoaded = false;

	_sharedNodeInfo = new SharedNodeInfo();

	mSmokeEngine = smokeEngine;
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
	delete(_sharedNodeInfo);
}
