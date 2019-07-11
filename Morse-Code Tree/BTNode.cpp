#include "BTNode.h"

BTNode::BTNode()
{
	letter = "";
	mCode = "";
	left = NULL;
	right = NULL;
}

BTNode::BTNode(const string& _letter, const string& _mCode, BTNode* _left, BTNode* _right)
{
	letter = _letter;
	mCode = _mCode;
	left = _left;
	right = _right;
}
