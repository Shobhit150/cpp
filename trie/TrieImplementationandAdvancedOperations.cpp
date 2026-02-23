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
                tmp->startCount++;
                tmp = tmp->arr[c-'a'];
            }
            tmp->equalCount++;
    	}

	    int countWordsEqualTo(string word) {
	        Node* tmp = root;
    	}

	    int countWordsStartingWith(string word) {
	        
    	}

	    void erase(string word) {
	        
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