#pragma once
#include <string>
using std::string;
struct Node
{
	Node();
	~Node();
	string letter;
	string codeSequence;
	Node* leftChild;
	Node* rightChild;
};

