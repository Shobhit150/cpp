#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long

class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s[0] == '0') return false;
        int i = 0;
        int n = s.size();
        while(i<n && s[i]=='1') i++;
        while(i<n && s[i]=='0') i++;
        if(i==n) return true;
        return false;
    }
};