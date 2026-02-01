#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution {
public:
    int bruteForce(vector<int>& nums, int i, int j) {
        if(i>j) return 0;
        int ans = INT_MIN;
        for(int k=i;k<=j;k++) {
            
            int cost = bruteForce(nums, i, k-1) +
                        bruteForce(nums, k+1, j) +
                        nums[k-1] * nums[k] * nums[k+1];
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
        return bruteForce(num, 1, m-2);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;
}