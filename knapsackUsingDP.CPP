#include <iostream> 
#include <vector> 
 
using namespace std; 
void printsolution(vector<vector<int>>& K, vector<int>& wt, int n, int W) { 
    cout << "Selected items: "; 
    int w = W; 
    for (int i = n; i > 0 && w > 0; i--) { 
        if (K[i][w] != K[i - 1][w]) { 
            cout << i << " "; 
            w -= wt[i - 1]; 
        } 
    } 
    cout << endl; 
} 
 
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) { 
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0)); 
 
    for (int i = 0; i <= n; i++) { 
        for (int w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
            else 
                K[i][w] = K[i - 1][w]; 
        } 
    } 
 
    printsolution(K, wt, n, W); 
 
    return K[n][W]; 
} 
 
 
 
int main() { 
    vector<int> val = {10,40,30,50}; 
    vector<int> wt = {5,4,6,3}; 
    int W = 10; 
    int n = val.size(); 
 
    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl; 

 
 
    return 0;
}