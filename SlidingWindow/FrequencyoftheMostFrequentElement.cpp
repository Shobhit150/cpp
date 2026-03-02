#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int sumi = 0;
        int ans = 1;
        for(int r=0;r<nums.size();r++) {
            sumi += nums[r];
            if((r-l+1) * nums[r] - sumi > k) {
                sumi -= nums[l];
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;

    }
};