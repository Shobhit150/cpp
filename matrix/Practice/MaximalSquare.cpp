#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int bruteForce(vector<vector<char>> &matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if( matrix[i][j] == '0') {
            return 0;
        }
        int k=1;
        while(i + k < m && j + k < n) {
            for(int c = j; c<j+k; c++) { // check column
                if(matrix[i+k][c] == '0') {
                    return k;
                }
            }

            for(int r = i; r<i+k; r++) { // check row
                if(matrix[r][j+k] == '0') {
                    return k;
                }
            }
            k++;
        }
        return k;
    }
    int bruteForce2(vector<vector<char>> &matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if( matrix[i][j] == '0') {
            return 0;
        }
        int right = bruteForce2(matrix, i+1, j);
        int bottom = bruteForce2(matrix, i, j+1);
        int diagnol = bruteForce2(matrix, i+1, j+1);

        return 1 + min({right, bottom, diagnol});
    }
    int memo(vector<vector<char>> &matrix, int i, int j, vector<vector<int>> &dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(i>=m || j>=n) return 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if( matrix[i][j] == '0') {
            return 0;
        }
        int right = memo(matrix, i+1, j, dp);
        int bottom = memo(matrix, i, j+1, dp);
        int diagnol = memo(matrix, i+1, j+1, dp);
        
        return dp[i][j] = 1 + min({right, bottom, diagnol});
    }
    int tab(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));
        int maxi = 0;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else if(i+1 == m || j+1 == n) {
                    dp[i][j] = 1;
                } else {
                    int right = dp[i+1][j];
                    int bottom = dp[i][j+1];
                    int diagnol = dp[i+1][j+1];
                    
                    dp[i][j] = 1 + min({right, bottom, diagnol});
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi*maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int>> dp(m, vector<int>(n,-1));

        // for(int i=0;i<m;i++) {
        //     for(int j=0;j<n;j++) {
        //         maxi = max(maxi, memo(matrix, i, j, dp));
        //     }
        // }
        return tab(matrix);
    }
};

int main(){
    Solution s;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << s.maximalSquare(matrix) << endl;
}