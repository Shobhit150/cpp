#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution {
public:
    // pair<int,int> true count / false count
    pair<int,int> bruteForce(string& s, int i, int j) {
        if(i==j) {
            if(s[i] == 'T') return {1,0};
            return {0,1};
        }
        int trueCount = 0;
        int falseCount = 0;
        for(int k=i+1;k<j;k+=2) {
            auto [leftT, leftF] = bruteForce(s,i,k-1);
            auto [rightT, rightF] = bruteForce(s,k+1,j);
            if(s[k] == '&') {
                trueCount += leftT * rightT;
                falseCount += (leftF*rightF) + (leftF*rightT) + (leftT*rightF);
            }
            if(s[k] == '|') {
                trueCount += (leftT*rightT) + (leftT*rightF) + (leftF*rightF);
                falseCount += leftF * rightF;
            }
            if(s[k] == '^') {
                trueCount += (leftT * rightF) + (leftF * rightT);
                falseCount += (leftT * rightT) + (leftF * rightF);
            }
        }
        return {trueCount, falseCount};
    }
    pair<int,int> memo(string& s, int i, int j, vector<vector<pair<int,int>>>& dp) {
        if(i==j) {
            if(s[i] == 'T') return {1,0};
            return {0,1};
        }
        if(dp[i][j].first != -1) {
            return dp[i][j];
        }
        int trueCount = 0;
        int falseCount = 0;
        for(int k=i+1;k<j;k+=2) {
            auto [leftT, leftF] = memo(s,i,k-1,dp);
            auto [rightT, rightF] = memo(s,k+1,j,dp);
            if(s[k] == '&') {
                trueCount += leftT * rightT;
                falseCount += (leftF*rightF) + (leftF*rightT) + (leftT*rightF);
            }
            if(s[k] == '|') {
                trueCount += (leftT*rightT) + (leftT*rightF) + (leftF*rightT);
                falseCount += leftF * rightF;
            }
            if(s[k] == '^') {
                trueCount += (leftT * rightF) + (leftF * rightT);
                falseCount += (leftT * rightT) + (leftF * rightF);
            }
        }
        return dp[i][j] = {trueCount, falseCount};
    }
    int tab(string &s) {
        int n = s.size();
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(n+1, {0,0}));
        for(int i=0;i<n;i++) {
            if(s[i] == 'T') dp[i][i] = {1,0};
            else dp[i][i] = {0,1};
        }

        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(i==j) continue;
                int trueCount = 0;
                int falseCount = 0;
                for(int k=i+1;k<j;k+=2) {
                    auto [leftT, leftF] = dp[i][k-1];
                    auto [rightT, rightF] = dp[k+1][j];
                    if(s[k] == '&') {
                        trueCount += leftT * rightT;
                        falseCount += (leftF*rightF) + (leftF*rightT) + (leftT*rightF);
                    }
                    if(s[k] == '|') {
                        trueCount += (leftT*rightT) + (leftT*rightF) + (leftF*rightT);
                        falseCount += leftF * rightF;
                    }
                    if(s[k] == '^') {
                        trueCount += (leftT * rightF) + (leftF * rightT);
                        falseCount += (leftT * rightT) + (leftF * rightF);
                    }
                }
                dp[i][j] = {trueCount, falseCount};
            }
        }
        return dp[0][n-1].first;
        
    }
    int countTrue(string s) {
        int n = s.size();
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(n+1, {-1,-1}));
        return tab(s);
    }
};

int main(){
    Solution s;
    string expr = "T|T&F^T";
    cout << s.countTrue(expr) << endl;
}