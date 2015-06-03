#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	class TrieNode{
	public:
		bool isend;
		TrieNode* children[26];
		int index;

		TrieNode(){
			isend = false;
			fill_n(children, 26, nullptr);
		};
		TrieNode* subNode(char ch)
		{
			return children[ch - 'a'];
		}
		TrieNode* addChildren(char ch)
		{
			if (nullptr == children[ch - 'a'])
				children[ch - 'a'] = new TrieNode();
			return children[ch - 'a'];
		}
	};
	class  Trie
	{
	public:
		TrieNode* root;

		Trie()
		{
			root = new TrieNode();
		}
		void build(vector<string>& words)
		{
			for (int i = 0; i < words.size(); i++)
				insert(words[i], i);
		}
		void insert(string word, int index)
		{
			TrieNode* r = root;
			for (auto ch : word)
			{
				r = r->addChildren(ch);
			}
			r->isend = true;
			r->index = index;
		}
	};

	void find(TrieNode* root, int row, int col)
	{
		if (board[row][col] == 'X')return;
		root = root->subNode(board[row][col]);
		if (nullptr == root)
			return;
		else
		{
			if (root->isend)
			{
				res.push_back(words[root->index]);
				root->isend = false;
			}
			char temp = board[row][col];
			board[row][col] = 'X';
			if (row > 0)find(root, row - 1, col);
			if (row + 1 < rows)find(root, row + 1, col);
			if (col > 0)find(root, row, col - 1);
			if (col + 1 < cols)find(root, row, col + 1);
			board[row][col] = temp;
		}
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		this->words = words;
		this->board = board;
		this->rows = board.size();
		if (rows == 0)return res;
		this->cols = board[0].size();
		if (cols == 0)return res;
		if (words.size() == 0)return res;
		Trie trie;
		trie.build(words);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				find(trie.root, i, j);
			}
		}
		return res;
	}
private:
	vector<string> res;
	vector<string> words;
	vector<vector<char>> board;
	int rows;
	int cols;
};

//int main()
//{
//	Solution s;
//
//	vector<vector<char>> board;
//	char* a[] = { "seenew", "tmriva", "obsibd", "wmysen", "ltsnsa", "iezlgn" };
//	for (auto str : a)
//	{
//		board.push_back(vector<char>(str, str + 6));
//	}
//
//	vector<string> words;
//	char* b[] = { "bend", "benda" };
//	for (auto str : b)
//	{
//		words.push_back(str);
//	}
//	vector<string> res = s.findWords(board, words);
//	for (auto s : res)
//	{
//		cout << s << endl;
//	}
//
//	/*char* my[] = { "stow", "stob", "seer", "seen", "embow", "neem", "wadna", "wave", "wene", "reem", "reest", "renew", "rine", "rive", "riva", "inerm", "irene", "vine", "vire", "avener", "avine", "bowl", "sise", "besa", "bend", "bena", "daven", "wots", "myst", "send", "teil", "sand", "sane", "sang", "anda", "anes", "anesis", "nane" };
//	char* a[] = { "anda", "anes", "anesis", "avener", "avine", "bena", "bend", "benda", "besa", "besan", "bowl", "daven", "embow", "inerm", "irene", "myst", "nane", "nanes", "neem", "reem", "reest", "renew", "rine", "riva", "rive", "riven", "sand", "sane", "sang", "seen", "seer", "send", "sise", "stob", "stow", "teil", "vine", "viner", "vire", "wadna", "wave", "wene", "wots" };
//	for (auto str1 : a)
//	{
//	bool flag = false;
//	for (auto str2 : my)
//	{
//	if (str1 == str2)
//	{
//	flag = true;
//	break;
//	}
//	}
//	if (!flag)
//	{
//	cout << str1 <<endl;
//	}
//	}*/
//}