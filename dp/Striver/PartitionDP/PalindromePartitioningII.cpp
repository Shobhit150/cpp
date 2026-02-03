#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalimdrome(string &s, int i, int j) {
        while(i<j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int memo(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i==j) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i;k<j;k++) {
            if(isPalimdrome(s,i,k)) {
                ans = min(ans, 1 + memo(s, k+1, j,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int bruteForce(string &s, int i, int j) {
        if(i==j) return 0;
        int ans = INT_MAX;
        for(int k=i;k<j;k++) {
            if(isPalimdrome(s,i,k)) {
                ans = min(ans, 1 + bruteForce(s, k+1, j));
            }
        }
        return ans;
    }
    int tab(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1;i>=0;i--) {
            for(int j=i+1;j<n;j++) {
                int ans = INT_MAX;
                for(int k=i;k<j;k++) {
                    if(isPalimdrome(s,i,k)) {
                        ans = min(ans, 1 + dp[k+1][j]);
                    }
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return tab(s);
    }
};

int main(){
    Solution s;
    string str = "ababbbabbaba";
    cout << s.minCut(str) << endl;
}