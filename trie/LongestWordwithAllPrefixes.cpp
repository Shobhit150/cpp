#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Node {
public:
    vector<Node*> arr;
    bool endsWith;
    Node() : arr(26,nullptr), endsWith(false) {};
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();

    }  
    void insert(string word) {
        Node* tmp = root;
        int count = 0;
        string countString = "";
        for(char &c: word) {
            if(!tmp->arr[c-'a']) {
                tmp->arr[c-'a'] = new Node();
            }
            tmp = tmp->arr[c-'a'];
        }
        tmp->endsWith = true;
    }
    bool allPrefixExist(string &word) {
        Node* tmp = root;
        for(char &c: word) {
            tmp = tmp->arr[c-'a'];
            if(!tmp || !tmp->endsWith) {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    string completeString(vector<string>& nums) {
        Trie t;
        for(string &str: nums) {
            t.insert(str);
        }
        int longest = 0;
        string longestString = "";
        for(string &str: nums) {
            if(t.allPrefixExist(str)) {
                if(str.size() > longest) {
                    longest = str.size();
                    longestString = str;
                }
                if(str.size() == longest) {
                    longestString = min(str, longestString);
                }
            }
        }
        return longestString == "" ? "None" : longestString;
    }
};