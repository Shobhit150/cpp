#include<iostream>
using namespace std;

class Node {
public:
    vector<Node*> arr;
    bool endsWith;
    Node(): arr(26, nullptr), endsWith(false) {};
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node(); 
    }
    
    void insert(string word) {
        Node* tmp = root;
        for(char &c: word) {
            if(!tmp->arr[c-'a']) {
                tmp->arr[c-'a'] = new Node();
            }
            tmp = tmp->arr[c-'a'];
        }
        tmp->endsWith = true;
    }
    
    bool search(string word) {
        Node* tmp = root;
        for(char &c: word) {
            if(tmp->arr[c-'a'] == nullptr) return false;
            tmp = tmp->arr[c-'a'];
        }
        if(tmp->endsWith) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(char &c: prefix) {
            if(tmp->arr[c-'a'] == nullptr) return false;
            tmp = tmp->arr[c-'a'];
        }
        return true;
    }
};