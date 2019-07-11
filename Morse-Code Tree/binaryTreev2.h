#pragma once
#include "BTNode.h"
#include <iostream>
using namespace std;

class binaryTree {
public:
	binaryTree();
	void add(string mCode, string letter);
	void add(BTNode *&node, string mCode, string letter,string &full_mCode);
	void decode(string code);
	void encode(string word);
	void in_order_mCode(BTNode* local_root, string code, string target);
	void in_order_letter(BTNode* local_root, string target);


private:
	BTNode *root;
};