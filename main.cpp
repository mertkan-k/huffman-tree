#include <iostream>

#include "huffman.hpp"

using namespace std;

int main()
{
	/*while (true)
	{
		cout << endl << "Please enter any alphabet letter for include: " << endl << "(Enter any number for start)";

		string ch;
		cin >> ch;

		if (!isalpha(ch[0]))
			break;

		ch[0] = ::toupper(ch[0]);

	}*/

	/*auto it = alphabetFreq.begin();
	for (size_t i = 0; i < 24; i++)
	{
		string ch = it->first;
		double fr = it->second;

		tTree* t = new tTree(ch, fr);

		l.push_back(t);
		cout << "include succes:: key: " << ch[0] << " " << "freq: " << fr << endl;

		it++;
	}*/

	Huffman* h = new Huffman();

	cout << "HELLO: " << h->Encrypt("HELLO") << endl;

	cout << "https://github.com/mertkan-k/" ;
	int gg; cin >> gg;
	return EXIT_SUCCESS;
}
