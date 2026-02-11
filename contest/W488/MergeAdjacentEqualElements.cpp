#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            st.push_back(nums[i]);
            while(st.size() >= 2 && st.back() == st[st.size()-2]) {

                long long val = st.back();
                st.pop_back();
                st.pop_back();

                st.push_back(val * 2);
            }
        }
        return st;
    }
};