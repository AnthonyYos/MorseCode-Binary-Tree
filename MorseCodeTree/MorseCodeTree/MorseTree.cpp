#include "MorseTree.h"

MorseTree::MorseTree()
{
	root = NULL;
}

void MorseTree::add(string letter, string codeSequence)
{
	add(root, codeSequence, letter, codeSequence);
}

void MorseTree::add(Node*& current, string codeSequence, string letter, const string fullSequence)
{
	if (current == NULL)
	{
		current = new Node();
	}

	if (codeSequence.empty())
	{
		current->letter = letter;
		current->codeSequence = fullSequence;
	}

	else
	{
		if (codeSequence[0] == '.')
			add(current->leftChild, codeSequence.substr(1), letter, fullSequence);
		else
			add(current->rightChild, codeSequence.substr(1), letter, fullSequence);
	}
}

void MorseTree::decode(string code)
{
	string space = " ";
	if (code.empty())
		return;
	inOrderCodeSequence(root, code.substr(0, code.find(space)), code.substr(0, code.find(space)));
	code = code.erase(0, code.find(space) + 1);
	decode(code);
	return;
}

void MorseTree::inOrderCodeSequence(Node* current, string codeSequence, string target)
{
	if (codeSequence.empty())
	{
		cout << current->letter;
		return;
	}

	if (codeSequence[0] == '.')
		inOrderCodeSequence(current->leftChild, codeSequence.substr(1), target);
	else
		inOrderCodeSequence(current->rightChild, codeSequence.substr(1), target);
}


void MorseTree::encode(string word)
{
	if (word.empty())
		return;
	findLetter(root, word.substr(0, 1));
	encode(word.substr(1, word.length()));
}

void MorseTree::findLetter(Node* current, string target)
{
	if (current->letter == target)

	{
		cout << current->codeSequence+" ";
		return;
	}
	if (target == " ")
	{
		cout << ' ';
		return;
	}

	if (current != nullptr)
	{
		if (current->leftChild != nullptr)
		{
			findLetter(current->leftChild, target);
		}

		if (current->rightChild != nullptr)
		{
			findLetter(current->rightChild, target);
		}
		else
			return;
	}
}

