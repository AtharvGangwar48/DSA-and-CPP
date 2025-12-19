// N-Queens Problem - Advanced Backtracking
// Use Case: Constraint satisfaction, game AI, scheduling conflicts

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_safe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    
    return true;
}

void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            board[row][col] = 'Q';
            backtrack(row + 1, n, board, result);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solve_n_queens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    backtrack(0, n, board, result);
    return result;
}

int main() {
    vector<vector<string>> solutions = solve_n_queens(4);
    cout << "Number of solutions for 4-Queens: " << solutions.size() << endl;
    
    for (auto& sol : solutions) {
        for (auto& row : sol)
            cout << row << endl;
        cout << endl;
    }
    return 0;
}
