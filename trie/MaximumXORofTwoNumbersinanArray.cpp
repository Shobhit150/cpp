#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
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
            int b = (n >> i) & 1;

            if (!tmp->arr[b])
                tmp->arr[b] = new Node();

            tmp = tmp->arr[b];
        }
    }

    int search(int n) {
        Node* tmp = root;
        int res = 0;
        for(int i=31;i>=0;i--) {
            int b = (n >> i) & 1;
            if(tmp->arr[1-b]) {
                res |= (1<<i);
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
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int i=0;i<nums.size();i++) {
            t.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            ans = max(ans,t.search(nums[i]));
        }
        return ans;
    }
};
int main() {
    vector<int> arr = {3,10,5,25,2,8};
    Solution s;
    cout << s.findMaximumXOR(arr) << "\n";
}