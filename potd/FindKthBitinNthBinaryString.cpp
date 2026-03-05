#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long

#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long

class Solution {
public:
    void invert(string &s) {
        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }
        reverse(s.begin(), s.end());
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1;i<n;i++) {
            string s2 = s;
            invert(s2);
            s = s + "1" + s2;
            // cout << i << " " << s << "\n";
        }
        
        return s[k-1];
    }
};