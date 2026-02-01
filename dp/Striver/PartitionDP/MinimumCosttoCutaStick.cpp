#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution {
public:
    int bruteForce(int l, int r, vector<int> &arr) {
        if(l>r) return 0;
        int ans = INT_MAX;
        for(int k=l;k<=r;k++) {
            int cost = bruteForce(l,k-1,arr) +
                        bruteForce(k+1,r,arr) +
                        (arr[r+1] - arr[l-1]);
            ans = min(ans, cost);
        }
        return ans;
    }
    int memo(int l, int r, vector<int> &arr, vector<vector<int>> &dp) {
        if(l>r) return 0;
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        int ans = INT_MAX;
        for(int k=l;k<=r;k++) {
            int cost = memo(l,k-1,arr,dp) +
                        memo(k+1,r,arr,dp) +
                        (arr[r+1] - arr[l-1]);
            ans = min(ans, cost);
        }
        return dp[l][r] = ans;
    }
    int tab(vector<int> &arr) {
        int m = arr.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1,0));

        for(int l=m-2;l>=1;l--) {
            for(int r=l;r<=m-2;r++) {
                int ans = INT_MAX;
                for(int k=l;k<=r;k++) {
                    int cost = dp[l][k-1] +
                                dp[k+1][r] +
                                (arr[r+1] - arr[l-1]);
                    ans = min(ans, cost);
                }
                dp[l][r] = ans;
            }
        }
        return dp[1][m-2];
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> arr;
        arr.push_back(0);
        for(int &num:cuts) {
            arr.push_back(num);
        }
        arr.push_back(n);
        int m = arr.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1,-1));
        return tab(arr);
    }
};

int main(){
    Solution s;
    vector<int> cuts = {1,3,4,5};
    int n = 7;
    cout << s.minCost(n, cuts) << endl;
}