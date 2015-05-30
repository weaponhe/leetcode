#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[row].size(); col++)
			{
				if (exist_dfs(board, word, row, col))
					return true;
			}
		}
		return false;
	}
	bool exist_dfs(vector<vector<char>>& board, string word, int row, int col)
	{
		if (word.length() == 1)
			return word[0] == board[row][col];
		else if (word[0] != board[row][col])
			return false;
		else
		{
			bool flag = false;
			//left
			flag = flag || (col > 0 && exist_dfs(board, word.substr(1, word.length()), row, col - 1));
			//right
			flag = flag || (col + 1 < board[row].size() && exist_dfs(board, word.substr(1, word.length()), row, col + 1));
			//up
			flag = flag || (row > 0 && col < board[row - 1].size() && exist_dfs(board, word.substr(1, word.length()), row - 1, col));
			//down
			flag = flag || (row + 1 < board.size() && col < board[row + 1].size() && exist_dfs(board, word.substr(1, word.length()), row + 1, col));
			return flag;
		}
	}
};

void mainsa()
{
	vector<vector<char>> board;
	char* str1 = "ABCE";
	char* str2 = "SFCS";
	char* str3 = "ADEE";
	vector<char> row1;
	vector<char> row2;
	vector<char> row3;

	char* p = str1;
	while (*p != '\0')
	{
		row1.push_back(*p);
		p++;
	}
	p = str2;
	while (*p != '\0')
	{
		row2.push_back(*p);
		p++;
	}
	p = str3;
	while (*p != '\0')
	{
		row3.push_back(*p);
		p++;
	}

	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);

	Solution* s = new Solution();
	cout << s->exist(board, "ABCCED") << endl;
	cout << s->exist(board, "SEE") << endl;
	cout << s->exist(board, "ABCF") << endl;
}