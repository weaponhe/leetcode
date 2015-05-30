#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution2 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> marks;
		for (int i = 0; i < board.size(); i++)
		{
			marks.push_back(vector<bool>(board[i].size(), false));
		}
		for (int row = 0; row < board.size(); row++)
		{
			for (int col = 0; col < board[row].size(); col++)
			{
				if (exist_dfs(board, marks, word, row, col))
					return true;
			}
		}
		return false;
	}
	bool exist_dfs(vector<vector<char>>& board, vector<vector<bool>> marks, string word, int row, int col)
	{
		marks[row][col] = true;
		if (word.length() == 1)
			return word[0] == board[row][col];
		else if (word[0] != board[row][col])
			return false;
		else
		{
			bool flag = false;
			//left
			flag = flag || (col > 0 && !marks[row][col - 1] && exist_dfs(board, marks, word.substr(1, word.length()), row, col - 1));
			if (flag)
				return flag;
			//right
			flag = flag || (col + 1 < board[row].size() && !marks[row][col + 1] && exist_dfs(board, marks, word.substr(1, word.length()), row, col + 1));
			if (flag)
				return flag;
			//up
			flag = flag || (row > 0 && col < board[row - 1].size() && !marks[row - 1][col] && exist_dfs(board, marks, word.substr(1, word.length()), row - 1, col));
			if (flag)
				return flag;
			//down
			flag = flag || (row + 1 < board.size() && col < board[row + 1].size() && !marks[row + 1][col] && exist_dfs(board, marks, word.substr(1, word.length()), row + 1, col));
			return flag;
		}
	}
};

void main()
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

	Solution2* s = new Solution2();
	cout << s->exist(board, "ba") << endl;
}