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
    int memo(string &s, int i, vector<int> &dp) {
        if(i==s.size()) return 0;
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans = INT_MAX;
        for(int k=i;k<s.size()-1;k++) {
            if(isPalimdrome(s,i,k)) {
                ans = min(ans, 1 + memo(s, k+1,dp));
            }
        }
        return dp[i] = ans;
    }
    int bruteForce(string &s, int i) {
        if(i==s.size()) return 0;
        int ans = INT_MAX;
        for(int k=i;k<s.size();k++) {
            if(isPalimdrome(s,i,k)) {
                ans = min(ans, 1 + bruteForce(s, k+1));
            }
        }
        return ans;
    }
    int tab(string &s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--) {
            int ans = INT_MAX;
            for(int k=i;k<s.size();k++) {
                if(isPalimdrome(s,i,k)) {
                    ans = min(ans, 1 + dp[k+1]);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
    }
    int minCut(string s) {
        int n = s.size();
        if(isPalimdrome(s,0,n-1)) return 0;
        vector<int> dp(n+1, -1);
        return tab(s);
    }
};

int main(){
    Solution s;
    string str = "ababbbabbaba";
    cout << s.minCut(str) << endl;
}