#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    long long bruteForce(vector<int>& nums1, vector<int>& nums2, int k, int i, int j) {
        if(k == 0) return 0;

        if(i == nums1.size() || j == nums2.size())
            return LLONG_MIN;

        long long ans = LLONG_MIN;
    
        
        ans = max(ans, bruteForce(nums1, nums2, k, i+1, j));

        ans = max(ans, bruteForce(nums1, nums2, k, i, j+1));

        long long nxt = bruteForce(nums1, nums2, k-1, i+1, j+1);

        if(nxt != LLONG_MIN) {
            ans = max(ans, nxt + 1LL * nums1[i] * nums2[j]);
        }
        return ans;
    }
    long long memo(vector<int>& nums1, vector<int>& nums2, int k, int i, int j, vector<vector<vector<long long>>> &dp) {
        if(k == 0) return 0;

        if(i == nums1.size() || j == nums2.size())
            return LLONG_MIN;

        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        long long ans = LLONG_MIN;
    
        
        ans = max(ans, memo(nums1, nums2, k, i+1, j, dp));

        ans = max(ans, memo(nums1, nums2, k, i, j+1, dp));

        long long nxt = memo(nums1, nums2, k-1, i+1, j+1, dp);

        if(nxt != LLONG_MIN) {
            ans = max(ans, nxt + 1LL * nums1[i] * nums2[j]);
        }
        return dp[i][j][k] = ans;
    }
    int tab(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<vector<long long>>> dp(
            n+1,
            vector<vector<long long>>(m+1,
                vector<long long>(k+1, LLONG_MIN)));

        dp[0][0][0] = 0;

        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                for(int l=0;l<=k;l++) {
                    long long ans = LLONG_MIN;
                    if(i < n)
                        dp[i+1][j][l] = max(dp[i+1][j][t], dp[i][j][t]);

                    if(j < m)
                        dp[i][j+1][l] = max(dp[i][j+1][t], dp[i][j][t]);

                    long long nxt = dp[i+1][j+1][l-1];

                    if(i < n && j < m && l < k) {
                        dp[i+1][j+1][l+1] =
                        max(dp[i+1][j+1][l+1],
                            dp[i][j][l] +
                            1LL * nums1[i] * nums2[j]);
                    }
                }
            }
        }
        return dp[n][m][k];
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1,-1)));
        
    }
};