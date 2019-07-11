#include "binaryTreev2.h"

binaryTree::binaryTree()
{
	root = NULL;
}

//Wrapper function for the other add
void binaryTree::add(string mCode, string letter)
{
	add(root, mCode, letter, mCode);
}

void binaryTree::add(BTNode*& node, string mCode, string letter, string &full_mCode)
{
	if (node == NULL)
	{
		node = new BTNode();
	}

	//When mCode's length = 0 then node knows it reached its path and will fill in the node, using letter and full_mCode
	if (mCode.empty())
	{
		node->letter = letter;
		node->mCode = full_mCode;
	}

	else // Creates/uses a path to a new/existing node based on the first char in the mCode substr
	{
		if (mCode[0] == '.')
			add(node->left, mCode.substr(1), letter, full_mCode);
		else
			add(node->right, mCode.substr(1), letter, full_mCode);
	}
}

//Morse code -> letters
void binaryTree::decode(string code)
{
	/*
	How to split a string with space
	string b = " ";
	cout << a.substr(0, a.find(b))<< endl; parses string from beginning to space
	cout << a.substr(a.find(b) + 1, a.length()) << endl; parses string from next non space to end; find(space)+1 puts beginning at char after the space*/

	string space = " "; //Used to split code into its individual mCode
	if (code.empty())//Ends function when code is empty
		return;
	in_order_mCode(root, code.substr(0, code.find(space)), code.substr(0, code.find(space)));
	code = code.erase(0, code.find(space) + 1);
	decode(code);//Recursive call of code
}

//Word -> morse code
void binaryTree::encode(string word)
{
	if (word.empty())//If word is empty function ends
		return;
	in_order_letter(root, word.substr(0, 1));//void function, cout mCode of word[0]
	encode(word.substr(1, word.length()));//Recursive call of word substr
}

//Traversing to find letter of a mCode
//Target is a mCode used to find the node w/ the same mCode and returns the letter of the node
//Intially codeSearch and target are the same
void binaryTree::in_order_mCode(BTNode* local_root, string codeSearch, string target)
{
	//When codeSearch is empty and local_root's mCode == target
	if (codeSearch.empty() && local_root->mCode == target)
	{
		cout << local_root->letter;
		return;
	}
	//Finds target by taking the first position in codeSearch choose whether going left or right and recursively calls function again with a substr of codeSearch from its next char to its length
	//Exactly the same as add function traversal
	if (codeSearch[0] == '.')
		in_order_mCode(local_root->left, codeSearch.substr(1), target);
	else
		in_order_mCode(local_root->right, codeSearch.substr(1), target);

}

//Traversing to find the mCode of a letter
//Target is a letter to find the node w/ the same letter, then returns the mCode of the ndoe
void binaryTree::in_order_letter(BTNode * local_root, string target)
{
	if (local_root->letter == target)

	{
		cout << local_root->mCode + " ";
		return;
	}
	if (target == " ") //Allows for a multiple word phrase in main, ending function immediately if space found
	{
		cout << '\t';
		return;
	}

	if (local_root != NULL)//Checks all left nodes before right nodes for target
	{
		if (local_root->left != NULL)
		{
			in_order_letter(local_root->left, target);
		}

		if (local_root->right != NULL)
		{
			in_order_letter(local_root->right, target);
		}
		else
			return;
	}
}

