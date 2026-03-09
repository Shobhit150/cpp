#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            map[u].push_back(v);
            map[v].push_back(u);
        }

        
    }
};