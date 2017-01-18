#ifndef _LIGHT_ATTACHMENT_NODE_H_
#define _LIGHT_ATTACHMENT_NODE_H_

#include <SmokeEngine.h>
#include "Node/AttachmentNode/AttachmentNode.h"
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;

class LightAttachmentNode :
	public AttachmentNode
{

public:
	Vector3f mColor;
	float mIntesnity;

	LightAttachmentNode(std::string id, SmokeEngine * Engine);
	~LightAttachmentNode(void);

	virtual std::string GetTypeName();
};

#endif