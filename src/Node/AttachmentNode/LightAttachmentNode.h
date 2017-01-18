#ifndef _LIGHT_ATTACHMENT_NODE_H_
#define _LIGHT_ATTACHMENT_NODE_H_

#include <SmokeEngine.h>
#include "Node/AttachmentNode/AttachmentNode.h"
#include "Utility/Vector/Vector3.h"

class LightAttachmentNode :
	public AttachmentNode
{

public:
	Vector3 mColor;
	float mIntesnity;

	LightAttachmentNode(std::string id, SmokeEngine * Engine);
	~LightAttachmentNode(void);

	virtual std::string GetTypeName();
};

#endif