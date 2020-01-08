#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

using namespace std;

#include <bits/stdc++.h>
#include <cstring>

typedef struct sTree
{
	string key;
	double frequency;
	struct sTree* left;
	struct sTree* right;

	sTree(string _key, double _frequency);

} tTree;

typedef list<tTree*> tTreeList;
typedef map<const char, double> tFrequencyMap;

struct treeComp{
	bool operator()(const sTree* p_1, const sTree* p_2) { return p_1->frequency < p_2->frequency; }
};

class Huffman
{
private:
	tTreeList m_l;
	tFrequencyMap m_fMap;
public:
	Huffman();
	Huffman(tFrequencyMap m);
	~Huffman();
private:
	void CreateTree(bool log=false);
	void ImportDefaultFrequencMap();
	void ImportMap(tFrequencyMap m);
public:
	string Encrypt(const char* message);
	void PrintTree();
	void Print(tTree* t);
};

#endif

