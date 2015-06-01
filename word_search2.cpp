#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		this->board = board;
		for (int i = 0; i < board.size(); i++)
			flag.push_back(vector<bool>(board[i].size(), false));

		vector<string> result;
		for (string word : words)
			if (exist(word))
				result.push_back(word);
		return result;
	}
	bool exist(string word) {
		this->word = word;
		for (int row = 0; row < board.size(); row++)
			for (int col = 0; col < board[row].size(); col++)
				if (exist(row, col, 0))
					return true;
		return false;
	}
private:
	vector<vector<char>> board;
	vector<vector<bool>> flag;
	string word;
	bool exist(int row, int col, int k)
	{
		if (flag[row][col] || word[k] != board[row][col])
			return false;
		if (k == word.length() - 1)
			return true;
		flag[row][col] = true;
		if ((col > 0 && exist(row, col - 1, k + 1))
			|| (col + 1 < board[row].size() && exist(row, col + 1, k + 1))
			|| (row > 0 && col < board[row - 1].size() && exist(row - 1, col, k + 1))
			|| (row + 1 < board.size() && col < board[row + 1].size() && exist(row + 1, col, k + 1)))
		{
			flag[row][col] = false;
			return true;
		}
		flag[row][col] = false;
		return false;
	}
};