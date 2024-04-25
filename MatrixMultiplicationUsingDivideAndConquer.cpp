#include <bits/stdc++.h> 
#include <chrono> 
#include <cstdlib> 
using namespace std; 
using namespace std::chrono; 
 
void matrix_addition(int n, int A[][100], int B[][100], int C[][100], int c_start, int c_end) { 
    for(int i = 0; i < n; ++i) { 
        for(int j = 0; j < n; ++j) { 
            C[i+c_start][j+c_end] = A[i][j] + B[i][j]; 
        } 
    } 
} 
 
void recursive_matrix_multiply( 
        int n, int A[][100], int B[][100], int C[][100], 
        int a_r_start, int a_r_end, int a_c_start,int a_c_end, 
        int b_r_start, int b_r_end, int b_c_start, int b_c_end 
    ) { 
    if(n == 1) { 
        C[0][0] = A[a_r_start][a_c_start] * B[b_r_start][b_c_start]; 

 
    } else { 
        int m = n/2; 
        int C1[100][100]; 
        int C2[100][100]; 
 
        recursive_matrix_multiply(m, A, B, C1, a_r_start, a_r_end-m, a_c_start, a_c_end-m, b_r_start, 
b_r_end-m, b_c_start, b_c_end-m); 
        recursive_matrix_multiply(m, A, B, C2, a_r_start, a_r_end-m, a_c_start+m, a_c_end, b_r_start+m, 
b_r_end, b_c_start, b_c_end-m); 
 
        matrix_addition(m, C1, C2, C, 0, 0); 
 
        recursive_matrix_multiply(m, A, B, C1, a_r_start, a_r_end-m, a_c_start, a_c_end-m, b_r_start, 
b_r_end-m, b_c_start+m, b_c_end); 
        recursive_matrix_multiply(m, A, B, C2, a_r_start, a_r_end-m, a_c_start+m, a_c_end, b_r_start+m, 
b_r_end, b_c_start+m, b_c_end); 
 
        matrix_addition(m, C1, C2, C, 0, m); 
 
        recursive_matrix_multiply(m, A, B, C1, a_r_start+m, a_r_end, a_c_start, a_c_end-m, b_r_start, 
b_r_end-m, b_c_start, b_c_end-m); 
        recursive_matrix_multiply(m, A, B, C2, a_r_start+m, a_r_end, a_c_start+m, a_c_end, b_r_start+m, 
b_r_end, b_c_start, b_c_end-m); 
 
        matrix_addition(m, C1, C2, C, m, 0); 
 
        recursive_matrix_multiply(m, A, B, C1, a_r_start+m, a_r_end, a_c_start, a_c_end-m, b_r_start, 
b_r_end-m, b_c_start+m, b_c_end); 
        recursive_matrix_multiply(m, A, B, C2, a_r_start+m, a_r_end, a_c_start+m, a_c_end, b_r_start+m, 
b_r_end, b_c_start+m, b_c_end); 
 
        matrix_addition(m, C1, C2, C, m, m); 
    } 
} 
 
int main() { 
    int A[4][100] = {{1, 2, 3, 4}, {4, 3, 2, 1}, { 0, 0, 1, 1 }, {1, 1, 0, 0}}; 
    int B[4][100] = {{2, 2, 4, 4}, {4, 1, 1, 4}, {1, 0, 1, 0}, {1, 0, 1, 0}}; 
    int C[4][100]; 
 
    recursive_matrix_multiply(4, A, B, C, 0, 3, 0, 3, 0, 3, 0, 3); 
 
    for(int i = 0; i < 4; ++i) { 
        for(int j = 0; j < 4; ++j) { 
            cout << C[i][j] << " "; 
        } 

 
        cout << endl; 
    } 
 
    return 0; 
}  
 
