#include<iostream>
using namespace std;
#define ll long long
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    // cout << i << " " << j << "\n";
                    ans++;
                }
            }
        }
        // for(int i=0;i<m;i++) {
        //     cout << row[i] << " ";
        // }
        // cout << "\n";
        // for(int i=0;i<n;i++) {
        //     cout << col[i] << " ";
        // }
        // cout << "\n";
        
        return ans;
    }
};