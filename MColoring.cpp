#include <iostream> 
using namespace std; 
 
const int infinity = 9999; 
int x[100]; 
 
void nextvalue(int k, int n, int m, int G[][100]); 
 
void mcoloring(int k, int G[][100], int n, int m) { 
    do { 
        nextvalue(k, n, m, G); 
 
        if (x[k] == 0) { 
              return; 
        } else { 
            if (k == n) { 
                for (int i = 0; i < n; i++) { 
                    cout << x[i] << " "; 
                } 
                cout << endl; 
                return; 
            } else { 
                mcoloring(k + 1, G, n, m); 
            } 
        } 
    } while (true); 
} 
 
void nextvalue(int k, int n, int m, int G[][100]) { 
    int i; 
    do { 
        x[k] = (x[k] + 1) % (m + 1); 

 
        if (x[k] == 0) { 
            return; 
        } 
        for (i = 0; i < n; i++) { 
            if (G[k][i] != 0 && x[i] == x[k]) { 
                break; 
            } 
        } 
        if (i == n) { 
            return; 
        } 
    } while (true); 
} 
 
int main() { 
    int n, m; 
 
    int G[100][100] = { 
        {0, 1, 1, 0}, 
        {1, 0, 1, 1}, 
        {1, 1, 0, 1}, 
        {0, 1, 1, 0} 
    }; 
 
    n = 4; 
    m = 3; 
 
    mcoloring(0, G, n, m); 
 
    return 0;}