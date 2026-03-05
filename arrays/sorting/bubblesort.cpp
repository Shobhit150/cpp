#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void sort(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n-1-i;j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};