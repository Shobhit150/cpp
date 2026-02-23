#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
    public:
    vector<Node*> arr;
    int equalCount;
    int startCount;
    Node() : arr(26, nullptr), equalCount(0), startCount(0) {};
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
                tmp->startCount++;
            }
            tmp->equalCount++;
    	}

	    int countWordsEqualTo(string word) {
	        Node* tmp = root;
            for(char &c: word) {
                if(!tmp->arr[c-'a']) {
                    return 0;
                }
                tmp = tmp->arr[c-'a'];
            }
            return tmp->equalCount;
    	}

	    int countWordsStartingWith(string word) {
	        Node* tmp = root;
            for(char &c: word) {
                if(!tmp->arr[c-'a']) {
                    return 0;
                }
                tmp = tmp->arr[c-'a'];
            }
            return tmp->startCount;
    	}

	    void erase(string word) {
	        Node* tmp = root;
            for(char &c: word) {
                if(!tmp->arr[c-'a']) {
                    return;
                }
                
                tmp = tmp->arr[c-'a'];
                tmp->startCount--;
            }
            tmp->equalCount--;
	    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */