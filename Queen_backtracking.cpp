#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    bool isSafe(int row, int col, vector<vector<char>>& board) 
   {
    // Horizontal and vertical checks
    for (int i = 0; i < board.size(); ++i) 
    {
        if (board[row][i] == 'Q' || board[i][col] == 'Q')
            return false;
    }

    // Upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) 
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Upper right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j) 
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Lower left diagonal
    for (int i = row, j = col; i < board.size() && j >= 0; ++i, --j) 
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Lower right diagonal
    for (int i = row, j = col; i < board.size() && j < board.size(); ++i, ++j) 
    {
        if (board[i][j] == 'Q')
            return false;
    }

      return true;
    }
    
    void saveBoard(vector<vector<char>>& board, vector<vector<string>>& allBoards) 
    {
        vector<string> newBoard;
        for (int i = 0; i < board.size(); ++i) 
        {
            string row = "";
            for (int j = 0; j < board[0].size(); ++j) 
            {
                if (board[i][j] == 'Q')
                    row += 'Q';
                else
                    row += '.';
            }
            newBoard.push_back(row);
        }
        allBoards.push_back(newBoard);
    }

    void helper(vector<vector<char>>& board, vector<vector<string>>& allBoards, int col) 
    {
        if (col == board.size()) 
        {
            saveBoard(board, allBoards);
            return;
        }

        for (int row = 0; row < board.size(); ++row) 
        {
            if (isSafe(row, col, board)) 
            {
                board[row][col] = 'Q';
                helper(board, allBoards, col + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> allBoards;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helper(board, allBoards, 0);
        return allBoards;
    }
    
};

int main() 
{
    Solution sol;
    int n;
    cout << "Enter N:" << endl;
    cin >> n;
    vector<vector<string>> result = sol.solveNQueens(n);
    for (const auto& board : result) 
    {
        for (const auto& row : board) 
        {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
