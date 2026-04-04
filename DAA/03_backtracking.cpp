// DAA - Backtracking: N-Queens, Sudoku Solver, Rat in a Maze
#include <bits/stdc++.h>
using namespace std;

// N-Queens
bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) if (board[i][j] == 'Q') return false;
    return true;
}

void solveNQueens(vector<string>& board, int row, int n, int& count) {
    if (row == n) { count++; return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(board, row+1, n, count);
            board[row][col] = '.';
        }
    }
}

// Sudoku Solver
bool isValidSudoku(vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) return false;
        int r = 3*(row/3) + i/3, c = 3*(col/3) + i%3;
        if (board[r][c] == num) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == 0)
                for (int num = 1; num <= 9; num++)
                    if (isValidSudoku(board, i, j, num)) {
                        board[i][j] = num;
                        if (solveSudoku(board)) return true;
                        board[i][j] = 0;
                    }
                    else if (num == 9) return false;
    return true;
}

// Rat in a Maze
bool ratMaze(vector<vector<int>>& maze, int x, int y, int n, vector<vector<int>>& sol) {
    if (x == n-1 && y == n-1) { sol[x][y] = 1; return true; }
    if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0) return false;
    sol[x][y] = 1;
    if (ratMaze(maze, x+1, y, n, sol) || ratMaze(maze, x, y+1, n, sol)) return true;
    sol[x][y] = 0;
    return false;
}

int main() {
    // N-Queens
    int n = 8;
    vector<string> board(n, string(n, '.'));
    int count = 0;
    solveNQueens(board, 0, n, count);
    cout << "N-Queens(" << n << "): " << count << " solutions\n\n";

    // Rat in a Maze
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{0,1,1,1}};
    vector<vector<int>> sol(4, vector<int>(4, 0));
    if (ratMaze(maze, 0, 0, 4, sol)) {
        cout << "Rat in Maze path:\n";
        for (auto& row : sol) { for (int x : row) cout << x << " "; cout << "\n"; }
    }
}
