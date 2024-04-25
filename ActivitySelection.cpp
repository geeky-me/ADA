#include <bits/stdc++.h> 
#include<vector> 
using namespace std; 
static bool cmp(pair<int,int>a,pair<int,int>b) 
{ 
    return a.second<b.second; 
} 
int maxmeetings(int start[], int end_l[],int n) 
{ 
 
 
    vector<pair<int,int>>v; 
    for(int i=0;i<n;i++) 
    { 
        pair<int,int>p=make_pair(start[i],end_l[i]); 
        v.push_back(p); 
    } 
 
    sort(v.begin(),v.end(),cmp); 
 
    int count = 1; 
    int ansend = v[0].second; 
    cout << v[0].first << endl; 
    for(int i=1;i<n;i++) 
    { 
        if(v[i].first>ansend) 
        { 
            count++; 
            cout <<  v[i].first << endl;; 
            ansend=v[i].second; 
        } 
    } 
    return count; 
} 
int main() 
{ 
    int start[5] = {1,3,5,6,8}; 
    int end_l[5] = {2,6,6,8,9}; 
    int n = maxmeetings(start,end_l,5); 
    cout << "The number of activities that can be done are:" << n ; 
    return 0; 
}