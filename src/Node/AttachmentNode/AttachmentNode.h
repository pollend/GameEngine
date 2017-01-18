#ifndef _ATTACHMENT_NODE_H_
#define _ATTACHMENT_NODE_H_

#include <SmokeEngine.h>
#include <Node/ObjectNode.h>
#include "Node/Node.h"

class AttachmentNode : public Node
{
protected:
	virtual void _onNodeAppend();
private:
	std::string _mask;
public:
	
	virtual std::string GetType();

	AttachmentNode(std::string ID, SmokeEngine * Engine) ;
	~AttachmentNode(void);

	/**
	*not implemented
	**/

	void SetMask(std::string mask);
	/**
	*not implemented
	**/
	std::string GetMask();


};

class AttachmentNodeCallback{
	public:
		AttachmentNodeCallback();
		virtual ~AttachmentNodeCallback();
		/**
		*callback used on the processing of attachment nodes to shader
		**/
		virtual void Callback(ObjectNode* objectNode, std::list<AttachmentNode*> attachmentNodes);
};

#endif