#pragma once
#include <string>
#include <fstream>
using namespace std;

struct BTNode
{
	//Variables
	string letter;
	string mCode;
	string fullCode;
	BTNode *left;
	BTNode *right;

	//Constructor
	BTNode();
	BTNode(const string& _letter, const string& _mCode, BTNode* left = NULL, BTNode* right = NULL);
};