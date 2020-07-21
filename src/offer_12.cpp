#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		int n_row = board.size();
		if(n_row == 0)
			return false;
		int n_col = board[0].size();
		if(n_col == 0)
			return false;
		vector<bool> visited(n_col*n_row, false);
		for(int i=0; i<n_row; ++i)
			for(int j=0; j<n_col; ++j)
				if(exist_helper(board, i, j, word, 0, visited, n_row, n_col))
					return true;
		return false;	
    }
	bool exist_helper(vector<vector<char>>& board, int i, int j, string word, int k, vector<bool>& visited, int n_row, int n_col){
		if ( i<0 || i>=n_row || j<0 || j>=n_col)
			return false;
		bool ans = false;
		if( visited[i*n_col+j] == false && board[i][j] == word[k] )
		{
			if(k+1 == word.size())
				return true;
			visited[i*n_col+j] = true;
			ans = exist_helper(board, i-1, j, word, k+1, visited, n_row, n_col) ||
					exist_helper(board, i+1, j, word, k+1, visited, n_row, n_col) ||
					exist_helper(board, i, j-1, word, k+1, visited, n_row, n_col) ||
					exist_helper(board, i, j+1, word, k+1, visited, n_row, n_col);
			visited[i*n_col+j] = false;
		}
		return ans;
	}
};

int main()
{
	//vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//string word = "ABCCED";
	vector<vector<char>> board = {{'A','B'}};
	string word = "BA";
	Solution *solution = new Solution();
	if(solution->exist(board, word))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
