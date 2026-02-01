#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) { // with non bitwise and 
        int n = nums.size();
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }   
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << s.longestSubsequence(nums) << endl;
}