#include<iostream>
using namespace std;
#define ll long long
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            int count = 0;
            for(int j=n-1;j>=0;j--) {
                if(grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            ans[i] = count;
        }
        int swaps = 0;
        for(int i=0;i<n;i++) {
            int need = n-i-1;
            int j = i;
            while(j<n && ans[j]<need) j++;
            if(j==n) return -1;
            
            for(int k=j;k>i;k--) {
                swap(ans[k],ans[k-1]);
                swaps++;
            }
        }
        return swaps;
    }
};