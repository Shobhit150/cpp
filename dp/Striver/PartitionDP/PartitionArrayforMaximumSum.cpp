#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution {
public: // 1 | 15 7 8 2 5 10
    int bruteForce(vector<int>& arr, int k, int i) {
        if(i==arr.size()) {
            return 0;
        }

        int maxi = 0;

        int maxValue = 0;
        int n = arr.size();

        for(int l=i;l<min(n,i+k);l++) {
            maxValue = max(maxValue, arr[l]);
            int len = l - i + 1;
            maxi = max(maxi,maxValue * len + bruteForce(arr,k,l+1));
        }
        return maxi;
    }
    int memo(vector<int>& arr, int k, int i, vector<int>& dp) {
        if(i==arr.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        int maxi = 0;

        int maxValue = 0;
        int n = arr.size();

        for(int l=i;l<min(n,i+k);l++) {
            maxValue = max(maxValue, arr[l]);
            int len = l - i + 1;
            maxi = max(maxi,maxValue * len + memo(arr,k,l+1,dp));
        }
        return dp[i] = maxi;
    }
    int tab(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--) {
            int maxi = 0;

            int maxValue = 0;

            for(int l=i;l<min(n,i+k);l++) {
                maxValue = max(maxValue, arr[l]);
                int len = l - i + 1;
                maxi = max(maxi,maxValue * len + dp[l+1]);
            }
            dp[i] = maxi;
        }
        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return tab(arr,k);
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << s.maxSumAfterPartitioning(arr, k) << endl;
}