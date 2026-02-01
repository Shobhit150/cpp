#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution {
public:
    int memo(vector<int>& nums, int i, int j, vector<vector<int>> &dp) {
        if(i>j) return 0;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k=i;k<=j;k++) {
            
            int cost = bruteForce(nums, i, k-1) +
                        bruteForce(nums, k+1, j) +
                        nums[i-1] * nums[k] * nums[j+1];
            ans = max(ans, cost);
        }
        return dp[i][j] = ans;
    }
    int tab(vector<int>& nums) {
        int m = nums.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int i=m-2;i>=1;i--) {
            for(int j=i;j<=m-2;j++) {
                int ans = INT_MIN;
                for(int k=i;k<=j;k++) {
                    
                    int cost = dp[i][k-1] +
                                dp[k+1][j] +
                                nums[i-1] * nums[k] * nums[j+1];
                    ans = max(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][m-2];
    }
    int bruteForce(vector<int>& nums, int i, int j) {
        if(i>j) return 0;
        int ans = INT_MIN;
        for(int k=i;k<=j;k++) {
            
            int cost = bruteForce(nums, i, k-1) +
                        bruteForce(nums, k+1, j) +
                        nums[i-1] * nums[k] * nums[j+1];
            ans = max(ans, cost);
        }
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> num;
        num.push_back(1);
        for(int &x: nums) num.push_back(x);
        num.push_back(1);
        int m = num.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return tab(num);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;
}