#include <iostream> 
#include <set> 
#include <vector> 
#include<climits> 
using namespace std; 
 
void print(set<pair<int, int>> s) 
{ 
    for (auto i : s) 
    { 
        cout << "{" << i.first << "," << i.second << "}" 
             << " , "; 
    } 
    cout << endl; 
} 
 
int find_max_value(set<pair<int, int>> &s) 
{ 
    int max_value = INT_MIN; 
    for (auto i : s) 
    { 
        max_value = max(max_value, i.first); 
    } 
    return max_value; 
} 
 
vector<int> find_max_path(set<pair<int, int>> &s, int max_value, vector<int> &p, vector<int> &w) 
{ 
    vector<int> path; 
    for (auto i : s) 
    { 
        if (i.first == max_value) 
        { 
            int remaining_weight = i.second; 

 
            for (int j = p.size() - 1; j >= 0; j--) 
            { 
                if (i.second - w[j] >= 0) 
                { 
                    path.push_back(j); 
                    remaining_weight -= w[j]; 
                    i.second -= w[j]; 
                } 
                if (remaining_weight == 0) 
                    break; 
            } 
            break; 
        } 
    } 
    reverse(path.begin(), path.end()); 
    return path; 
} 
 
set<pair<int, int>> merge_purge(set<pair<int, int>> &s1, set<pair<int, int>> &s2, int W) 
{ 
    set<pair<int, int>> s3; 
    for (auto i : s1) 
    { 
        for (auto j : s2) 
        { 
            if (i.second <= W && j.second <= W) 
            { 
                if (i.first < j.first && i.second > j.second) 
                { 
                    continue; 
                } 
                s3.insert(i); 
                s3.insert(j); 
            } 
        } 
    } 
    return s3; 
} 
 
void knapsack(int n, vector<int> &p, vector<int> &w, int W) 
{ 
    set<pair<int, int>> s1 = {{0, 0}}; 
    for (int i = 0; i < n; i++) 
    { 
        set<pair<int, int>> s2; 
        for (auto j : s1) 
 
 
        { 
            s2.insert({j.first + p[i], j.second + w[i]}); 
        } 
        s1 = merge_purge(s1, s2, W); 
    } 
    print(s1); 
    int max_value = find_max_value(s1); 
    cout << "Maximum value: " << max_value << endl; 
 
    vector<int> path = find_max_path(s1, max_value, p, w); 
    cout << "Selected items for maximum value: "; 
    for (int i = 0; i < path.size(); i++) 
    { 
        cout << path[i] << " "; 
    } 
    cout << endl; 
} 
 
int main() 
{ 
    int n = 4; 
    vector<int> p = {10, 40, 30, 50}; 
    vector<int> w = {5, 4, 6, 3}; 
    int W = 10; 
 
    knapsack(n, p, w, W); 
 
    return 0; 
} 
