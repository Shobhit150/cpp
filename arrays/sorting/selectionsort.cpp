#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void sort(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int mini = i;
            for(int j=i+1;j<n;j++) {
                if(nums[j] < nums[mini]) {
                    mini = j;
                }
            }
            swap(nums[mini], nums[i]);
        }
    }
};