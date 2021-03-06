#include "Node/SharedNodeInfo.h"

SharedNodeInfo::SharedNodeInfo(void)
{
	mNodes = new std::map<std::string, Node*>();
	mAttachmentNodes = new std::map<std::string, std::list<AttachmentNode*> >;
}


SharedNodeInfo::~SharedNodeInfo(void)
{
	delete(mNodes);
	delete(mAttachmentNodes);

}
