#include <iostream>

#include "huffman.hpp"

using namespace std;

int main()
{
	cout << "Chose your alphabet frequency list:" << endl;
	cout << "1: for use default" << endl;
	cout << "2: for define own alphabet" << endl;
	cout << "3: import from file" << endl;

	char c;
	cin >> c;

	Huffman* h;

	if (c == '1')
	{
		h = new Huffman();
	}
	else if (c == '2')
	{
		tFrequencyMap f;

		while (true)
		{
			cout << endl << "Please enter any alphabet letter for include: " << endl << "(Enter any number if you don't want any more)";

			char ch; cin >> ch;

			if (!isalpha(ch))
				break;

			// ch[0] = ::toupper(ch);

			cout << endl << "Please enter frequency of " << ch << endl;
			double fq; cin >> fq;

			cout << "Succesful:: " << ch << ":" << fq << endl;
			f[ch] = fq;
		}

		h = new Huffman(f);
	}
	else if (c == '3')
	{
		cout << "File formatting example:" << endl;
		cout << "<character> <frequency>" << endl;
		cout << "A 1.3212" << endl;
		cout << "B 1.1132" << endl;
		cout << "Please enter file name for importing: ";
		string fileName; cin >> fileName;

		ifstream importFile;
		importFile.open(fileName, ios::in );

		char ch; double fq; tFrequencyMap f;
		while (importFile >> ch >> fq)
		{
			cout << "Succesful:: " << ch << ":" << fq << endl;
			f[ch] = fq;
		}

		h = new Huffman(f);
	}

	cout << "Import completed!" << endl;

	while (true)
	{
		cout << "Enter word(s) for encrypt: ";

		string enc; cin >> enc;

		cout << enc << " :" << h->Encrypt(enc.c_str()) << endl;
	}

	return EXIT_SUCCESS;
}
