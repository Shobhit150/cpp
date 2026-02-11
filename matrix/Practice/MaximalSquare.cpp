#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution {
public:
    int bruteForce(vector<vector<char>> &matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if( matrix[i][j] == '0') {
            return 0;
        }
        int k=1;
        while(i + k < m && j + k < n) {
            for(int c = j; c<j+k; c++) { // check column
                if(matrix[i+k][c] == '0') {
                    return k;
                }
            }

            for(int r = i; r<i+k; r++) { // check row
                if(matrix[r][j+k] == '0') {
                    return k;
                }
            }
            k++;
        }
        return k;
    }
    int memo()
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                maxi = max(maxi, bruteForce(matrix, i, j));
            }
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
    cout << s.maximalSquare(matrix) << endl;
}