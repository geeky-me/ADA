#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> result(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If matrix size is 1x1
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Divide the matrices into quarters
    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));

    // Split A and B matrices into quarters
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Compute intermediate matrices
    vector<vector<int>> M1 = multiplyMatrix(addMatrix(A11, A22), addMatrix(B11, B22));
    vector<vector<int>> M2 = multiplyMatrix(addMatrix(A21, A22), B11);
    vector<vector<int>> M3 = multiplyMatrix(A11, subtractMatrix(B12, B22));
    vector<vector<int>> M4 = multiplyMatrix(A22, subtractMatrix(B21, B11));
    vector<vector<int>> M5 = multiplyMatrix(addMatrix(A11, A12), B22);
    vector<vector<int>> M6 = multiplyMatrix(subtractMatrix(A21, A11), addMatrix(B11, B12));
    vector<vector<int>> M7 = multiplyMatrix(subtractMatrix(A12, A22), addMatrix(B21, B22));

    // Compute the products of submatrices
    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    vector<vector<int>> C12 = addMatrix(M3, M5);
    vector<vector<int>> C21 = addMatrix(M2, M4);
    vector<vector<int>> C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);

    // Merge the results into a single matrix
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + mid] = C12[i][j];
            result[i + mid][j] = C21[i][j];
            result[i + mid][j + mid] = C22[i][j];
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    for (int size = 2; size <= 32; size *= 2) {
        vector<vector<int>> A(size, vector<int>(size));
        vector<vector<int>> B(size, vector<int>(size));

        // Generate random numbers for the matrices
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                A[i][j] = rand() % 100; // Generate random numbers between 0 and 99
                B[i][j] = rand() % 100; // Generate random numbers between 0 and 99
            }
        }

        auto start = high_resolution_clock::now(); // Start time

        vector<vector<int>> result = multiplyMatrix(A, B); // Perform matrix multiplication

        auto stop = high_resolution_clock::now(); // Stop time

        auto duration = duration_cast<microseconds>(stop - start);
     cout << "Size: " << size << ", Time taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}