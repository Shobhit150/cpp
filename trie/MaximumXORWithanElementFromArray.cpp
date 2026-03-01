#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Node {
public:
    Node* arr[2];
    Node() {
        arr[0] = arr[1] = nullptr;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int n) {
        Node* tmp = root;
        for(int i=31;i>=0;i--) {
            int b = (n>>i) & 1;
            if(!tmp->arr[b]) {
                tmp->arr[b] = new Node();
            }
            tmp = tmp->arr[b];
        }
    }
    int search(int n) {
        int res = 0;
        Node* tmp = root;
        for(int i=31;i>=0;i--) {
            int b = (n>>i) & 1;
            if(tmp->arr[1-b]) {
                res |= (1 << i);
                tmp = tmp->arr[1-b];
            } else {
                tmp = tmp->arr[b];
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(),
            [](vector<int> &a, vector<int>&b) {
                return a[1] < b[1];
            }
        );

        Trie t;
        
        vector<int> res;
        int j = 0;
        for(int i=0;i<queries.size();i++) {
            int x = queries[i][0];
            int m = queries[i][1];
            while(j < nums.size() && nums[j] <= m) {
                t.insert(nums[j]);
                j++;
            }
            
            if (j > 0)
                res.push_back(t.search(x));
        }
        return res;
    }
};
int main() {
    vector<int> nums = {0,1,2,3,4};
    vector<vector<int>> queries = {{3,1},{1,3},{5,6}};
    Solution s;
    vector<int> arr = s.maximizeXor(nums, queries);
    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
}

// #include<iostream>
// #include<string>
// #include<vector>
// #include<unordered_set>
// #include<algorithm>
// using namespace std;

// class Node {
// public:
//     Node* arr[2];
//     Node() {
//         arr[0] = arr[1] = nullptr;
//     }
// };
// class Trie {
// public:
//     Node* root;
//     Trie() {
//         root = new Node();
//     }
//     void insert(int n) {
//         Node* tmp = root;
//         for(int i=31;i>=0;i--) {
//             int b = (n>>i) & 1;
//             if(!tmp->arr[b]) {
//                 tmp->arr[b] = new Node();
//             }
//             tmp = tmp->arr[b];
//         }
//     }
//     int search(int n) {
//         int res = 0;
//         Node* tmp = root;
//         for(int i=31;i>=0;i--) {
//             int b = (n>>i) & 1;
//             if(tmp->arr[1-b]) {
//                 res |= (1 << i);
//                 tmp = tmp->arr[1-b];
//             } else {
//                 tmp = tmp->arr[b];
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
//         sort(nums.begin(), nums.end());
        
//         vector<int> res;
//         for(int i=0;i<queries.size();i++) {
//             int x = queries[i][0];
//             int m = queries[i][1];
//             if(nums[0] > m) {
//                 res.push_back(-1);
//                 continue;
//             }
//             Trie t;
//             for(int j=0;j<nums.size();j++) {
//                 if(nums[j] > m) break;
//                 t.insert(nums[j]);
//             }
//             int num = t.search(x);
//             res.push_back(num);
//         }
//         return res;
//     }
// };
// int main() {
//     vector<int> nums = {0,1,2,3,4};
//     vector<vector<int>> queries = {{3,1},{1,3},{5,6}};
//     Solution s;
//     vector<int> arr = s.maximizeXor(nums, queries);
//     for(int i=0;i<arr.size();i++) {
//         cout << arr[i] << " ";
//     }
// }

