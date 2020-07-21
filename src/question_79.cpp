#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
 		int n_row = board.size();
		if (n_row == 0) return false;
		int n_col = board[0].size();
		if (n_col == 0) return false;	
		
		for (int i=0; i<n_row; ++i)
			for (int j=0; j<n_col; ++j)
				if (exist_helper(board, i, j, word, 0, n_row, n_col))
					return true;
		return false;
    }
	bool exist_helper(vector<vector<char>>& board, int i, int j, string word, int k, int n_row, int n_col)
	{
		if (i<0 || i>n_row || j<0 || j>n_col)
			return false;
		bool a=false, b=false, c=false, d=false;
		if (board[i][j] == word[k])
		{
			if (k == word.size()-1)
				return true;
			char ch = board[i][j];
			board[i][j] = '#';
			if(i>=1 && board[i-1][j] == word[k+1])
				a = exist_helper(board, i-1, j, word, k+1, n_row, n_col);
			if(i+1<n_row && board[i+1][j] == word[k+1])
				b = exist_helper(board, i+1, j, word, k+1, n_row, n_col);
			if(j>=1 && board[i][j-1] == word[k+1])
				c = exist_helper(board, i, j-1, word, k+1, n_row, n_col);
			if(j+1<n_col && board[i][j+1] == word[k+1])
				d = exist_helper(board, i, j+1, word, k+1, n_row, n_col);
			board[i][j] = ch;
		}
		return a || b || c || d;
	}
};


int main()
{
	vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string word = "ABCB";
	Solution *solution = new Solution();
	if (solution->exist(board, word))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
