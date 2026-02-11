#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            int num = nums[i];
            double avg = 0;
            for(int j=i+1;j<n;j++) {
                avg += nums[j];
            }
            avg = avg/(n-i);
            if(num > avg) count++;
        }
        return count;
    }
};