#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed at position (row, col)
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve N-Queens problem using backtracking
void solveNQueensUtil(vector<vector<int>>& board, int N, int row, vector<vector<vector<int>>>& solutions) {
    if (row == N) {
        // Found a solution, add it to the list of solutions
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            solveNQueensUtil(board, N, row + 1, solutions);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

// Function to solve N-Queens problem and find all solutions
vector<vector<vector<int>>> solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<vector<int>>> solutions;
    solveNQueensUtil(board, N, 0, solutions);
    return solutions;
}

// Function to print the N-Queens solution
void printSolution(const vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}


int main() {
    int N;
    cout << "Enter the number of queens (N): ";
     cin >> N;

    vector<vector<vector<int>>> solutions = solveNQueens(N);

    if (solutions.empty()) {
        cout << "No solutions found.";
        return 0;
    }

    cout << "Found " << solutions.size() << " solutions:\n";
    for (const auto& solution : solutions)
        printSolution(solution);

    return 0;
}
