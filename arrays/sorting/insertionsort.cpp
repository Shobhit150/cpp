#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void sort(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++) {
            int key = nums[i];
            int j = i - 1;
            while(nums[j] > key) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = key;
        }
    }
};