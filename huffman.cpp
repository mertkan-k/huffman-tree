#include "huffman.hpp"

sTree::sTree(string _key, double _frequency)
{
	left = right = NULL;

	key = _key;
	frequency = _frequency;
}

Huffman::Huffman(tFrequencyMap m)
{
	m_fMap = m;

	CreateTree();
}

Huffman::Huffman()
{
	ImportDefaultFrequencMap();

	CreateTree();
}

Huffman::~Huffman()
{
	// TODO: free tree
}

void Huffman::CreateTree(bool log)
{
	for (auto &&i : m_fMap)
		m_l.push_back(new tTree(string(1, i.first), i.second));

	while (true)
	{
		if (m_l.size() < 2)
			break;

		auto it = m_l.begin();

		tTree* it_1 = *it;
		advance(it, 1);
		tTree* it_2 = *it;

		tTree* t = new tTree("(" + (it_2)->key + (it_1)->key + ")", (it_1)->frequency + (it_2)->frequency);
		t->left = it_2;
		t->right = it_1;

		m_l.remove(it_1);
		m_l.remove(it_2);

		m_l.push_back(t);

		m_l.sort(treeComp());

		if (log)
		{
			for (auto i = m_l.begin(); i != m_l.end(); i++)
			{
				cout << (*i)->key << ": " << (*i)->frequency << endl;
			}
			cout << "---------------------------------------------------------" << endl;
		}
	}
}

void Huffman::PrintTree()
{
	Print(*m_l.begin());
}
void Huffman::Print(tTree* t)
{
	if (t->right)
		Print(t->right);
	if (t->left)
		Print(t->left);

	if (t->key.length() == 1)
		cout << t->key << ": " << Encrypt(t->key.c_str()) << endl;
}

string Huffman::Encrypt(const char* message) // TODO: remove space + stirng to char[]
{
	string ret;

	for (size_t i = 0; i < strlen(message); i++)
	{
		tTree* t = *m_l.begin();

		while (t != NULL)
		{
			if(t->left && t->left->key.find(message[i]) != std::string::npos)
			{
				ret += "0";
				t = t->left;
			}
			else if (t->right)
			{
				ret += "1";
				t = t->right;
			}
			else
			{
				break;
			}
			
		}

		ret += " ";
	}
	
	return ret;
}

void Huffman::ImportDefaultFrequencMap()
{
	m_fMap['A'] = 0.0817;
	m_fMap['B'] = 0.0145;
	m_fMap['C'] = 0.0248;
	m_fMap['D'] = 0.0431;
	m_fMap['E'] = 0.1232;
	m_fMap['F'] = 0.0209;
	m_fMap['G'] = 0.0182;
	m_fMap['H'] = 0.0668;
	m_fMap['I'] = 0.0689;
	m_fMap['J'] = 0.0010;
	m_fMap['K'] = 0.0080;
	m_fMap['L'] = 0.0397;
	m_fMap['M'] = 0.0277;
	m_fMap['N'] = 0.0662;
	m_fMap['O'] = 0.0781;
	m_fMap['P'] = 0.0156;
	m_fMap['Q'] = 0.0009;
	m_fMap['R'] = 0.0572;
	m_fMap['S'] = 0.0628;
	m_fMap['T'] = 0.0905;
	m_fMap['U'] = 0.0304;
	m_fMap['V'] = 0.0102;
	m_fMap['W'] = 0.0264;
	m_fMap['X'] = 0.0015;
	m_fMap['Y'] = 0.0211;
	m_fMap['Z'] = 0.0005;
}

void Huffman::ImportMap(tFrequencyMap m){
	m_fMap = m;
}
