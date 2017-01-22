#ifndef _SCENE_NODE_H_
#define _SCENE_NODE_H_

#include <Node/Camera.h>
#include "InputEvent.h"

class Node;
class SharedNodeInfo;
class SmokeEngine;
class Renderer;
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
			RootNode(SharedNodeInfo* sharedNodeInfo, std::string ID);
			virtual std::string GetType();
	};
public:

	SmokeEngine * mSmokeEngine;

	/**
	*updates the scene with the given deltaT value
	**/
	virtual void Update(float deltaT) =0;
	virtual void Input(InputEvent* Event) = 0;

	virtual void Load();
	virtual void UnLoad();
	virtual void Initialize() = 0;
	virtual void Draw(Renderer* renderer) = 0;

	bool IsLoad();

	SceneNode( SmokeEngine* smokeEngine);
	~SceneNode(void);
};

#endif

