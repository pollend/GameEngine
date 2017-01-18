#ifndef _SCENE_NODE_H_
#define _SCENE_NODE_H_

#include <Storage/ViewStorage.h>
#include <Utility/Camera.h>
#include "InputEvent.h"

class Node;
class SharedNodeInfo;
class SmokeEngine;
class SceneNode
{
private:
	bool _isLoaded;
	//node information that is shared between all the nodes
	SharedNodeInfo* _sharedNodeInfo;
protected:
	class RootNode : public Node
	{
		public:
			RootNode(SceneNode * sceneNode,SharedNodeInfo* sharedNodeInfo, std::string ID);
			virtual std::string GetType();
	};
public:
	//the main camera 
	Camera * mMainCamera;

	ViewStorage * mViewStorage;
	RootNode * mRootSceneNode;
	RootNode * mRootOverlayNode;

	SmokeEngine * mSmokeEngine;

	/**
	*updates the scene with the given deltaT value
	**/
	virtual void Update(float deltaT) =0;
	virtual void Input(InputEvent* Event) = 0;

	virtual void Load();
	virtual void UnLoad();
	virtual void Inintalize() = 0;
	virtual void InintalizeScene() = 0;

	bool IsLoad();

	SceneNode( SmokeEngine* smokeEngine,Camera * camera);
	~SceneNode(void);
};

#endif

