#include "MorseTree.h"
#include <fstream>
using std::fstream;

void main()
{
	MorseTree tree;
	string letter, code, morseCode;
	fstream input("MorseSequence.txt");

	while(!input.eof())
	{
		input >> morseCode;
		letter = morseCode.substr(0, 1);
		code = morseCode.substr(1, morseCode.length());
		tree.add(letter, code);
	}
	cout << "My name is ";
	tree.encode("anthony");
	cout << " -> ";
	tree.decode("._ _. _ .... ___ _. _.__ ");
	tree;
}