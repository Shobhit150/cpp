#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        deque<int> maxdq, mindq;
        int n = nums.size();

        long long ans = 0;
        int l = 0;
        for(int r=0;r<n;r++) {
            while(!maxdq.empty() && nums[maxdq.back()] <= nums[r]) {
                maxdq.pop_back();
            }
            maxdq.push_back(r);
            while(!mindq.empty() && nums[mindq.back()] >= nums[r]) {
                mindq.pop_back();
            }
            mindq.push_back(r);

            while(l<=r) {
                long long mx = nums[maxdq.front()];
                long long mn = nums[mindq.front()];


                int len = r - l + 1;
                if((mx-mn) * len <= k) break;

                if(l==maxdq.front()) maxdq.pop_front();
                if(l==mindq.front()) mindq.pop_front();
                l++;
            }
            ans += (r-l+1);

        }
        return ans;
    }
};