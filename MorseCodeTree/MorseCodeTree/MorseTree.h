#pragma once
#include "Node.h"
#include<iostream>
using std::cout;

class MorseTree {
public:
	MorseTree();
	void add(string letter, string codeSequence);
	void add(Node *&current, string mCode, string letter, const string fullSequence);
	void decode(string sequence);
	void inOrderCodeSequence(Node* current, string code, string target);
	void encode(string word);
	void findLetter(Node* current, string target);


private:
	Node *root;
};