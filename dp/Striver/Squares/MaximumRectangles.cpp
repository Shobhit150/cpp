#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMaxRectangle(vector<int> &mat) {
        int n = mat.size();
        vector<int> stack;
        vector<int> next(n,n);
        vector<int> prev(n,-1);
        for(int i=0;i<n;i++) {
            while(!stack.empty() && mat[stack.back()] >= mat[i]) {
                stack.pop_back();
            }
            if(!stack.empty()) {
                prev[i] = stack.back();
            }
            stack.push_back(i);
        }
        while(!stack.empty()) stack.pop_back();

        for(int i=n-1;i>=0;i--) {
            while(!stack.empty() && mat[stack.back()] >= mat[i]) {
                stack.pop_back();
            }
            if(!stack.empty()) {
                next[i] = stack.back();
            }
            stack.push_back(i);
        }
        int maxi = 0;

        for(int i=0;i<n;i++) {
            int len = next[i] - prev[i] - 1;
            maxi = max(maxi, len * mat[i]);
        }
        return maxi;
    }
    int maximalAreaOfSubMatrixOfAll1(vector<vector<char>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arr(n,0);
        int maxi = 0;
        for(int i=0;i<m;i++) { 
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == '1') {
                    arr[j]++;
                } else {
                    arr[j] = 0;
                }
            }
            maxi = max(maxi, findMaxRectangle(arr));
        }
        return maxi;
    }
};
int main(){
    Solution s;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << s.maximalAreaOfSubMatrixOfAll1(matrix) << endl;
}