#include "binaryTreev2.h"
#include <fstream>

//Anthony Yos
void main()
{
	binaryTree tree;
	ifstream fin("morse.txt");
	string mCode, letter, phrase;

	while (!fin.eof()) //While loop to fill in tree
	{
		fin >> phrase;
		letter = phrase.substr(0, 1);
		mCode = phrase.substr(1, phrase.length());
		tree.add(mCode, letter);
	}
	tree.encode("apple");
	cout << endl;
	tree.encode("it actually works");//Long spaces in console indicates the next word
	cout << endl;
	tree.decode("._ .__. .__. ._.. . ");
	cout << endl;
	tree; //Used to check the tree
	system("pause");
}