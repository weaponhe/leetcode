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