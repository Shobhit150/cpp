#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;
        int acount = 0;
        int bcount = 0;
        int j = 0;
        int ans = INT_MAX;
        for(int i=0;i<s2.size();i++) {
            char expected1 = ((i%2) == 0) ? '0' : '1';
            char expected2 = ((i%2) == 0) ? '1' : '0';

            if(expected1 != s2[i]) {
                acount++;
            }
            if(expected2 != s2[i]) {
                bcount++;
            }
            if(i-j >= n) {
                char left1 = ((j%2) == 0) ? '0' : '1';
                char left2 = ((j%2) == 0) ? '1' : '0';

                if(s2[j] != left1) {
                    acount--;
                }
                if(s2[j] != left2) {
                    bcount--;
                }
                j++;
            }
            if(i-j+1 == n) {
                ans = min(ans, min(acount, bcount));
            }
        }
        return ans;
    }
};