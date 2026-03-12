#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long
class Solution {
public:
    int dp[201][201][2][201];
    int MOD = 1e9 + 7;
    int bruteForce(int zero, int one, int limit, int i, int j, int consecutiveZero, int consecutiveOnes) {
        if(consecutiveOnes > limit || consecutiveZero > limit) return 0;
        if(i == zero && j == one) return 1;
        int sumi = 0;
        if(i < zero) {
            sumi += bruteForce(zero, one, limit, i+1, j, consecutiveZero+1, 0);
        }
        if(j<one) {
            sumi += bruteForce(zero, one, limit, i, j+1, 0, consecutiveOnes+1);
        }
        return sumi;
    }
    int memo(int zero, int one, int limit, int i, int j, int last, int cnt) {
        if(cnt > limit) return 0;
        if(dp[i][j][last][cnt] != -1) {
            return dp[i][j][last][cnt];
        }
        if(i == zero && j == one) return 1;
        long long ans = 0;

        if(i < zero) {
            if(last == 0) {
                ans += memo(zero, one, limit, i+1, j, 0, cnt+1);
            } else {
                ans += memo(zero, one, limit, i+1, j, 0, 1);
            }
        }
        if(j<one) {
            if(last == 1) {
                ans += memo(zero, one, limit, i, j+1, 1, cnt+1);
            } else {
                ans += memo(zero, one, limit, i, j+1, 1, 1);
            }
        }
        return dp[i][j][last][cnt] = ans % MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        long long ans = 0;
        if(zero > 0)
            ans += memo(zero,one,limit,1,0,0,1);

        if(one > 0)
            ans += memo(zero,one,limit,0,1,1,1);

        return ans % MOD;
    }
};