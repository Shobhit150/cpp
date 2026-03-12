#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 0;
        int ans = 0;
        int count = 0;
        while(n) {
            int b = (n & 1) ? 0 : 1;
            ans |= (b << count);
            n >>= 1;
            count++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n; 
    cin >> n;
    cout << s.bitwiseComplement(n);
}