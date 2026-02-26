#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Node {
public:
	vector<Node*> arr;
	Node() : arr(26, nullptr) {};
};

class Trie {
public:
	Node* root;
	int count;
	Trie() : root(new Node()), count(1) {};

	void insert(std::string &word, int k) {
		Node* tmp = root;
		for(int i=k;i<word.size();i++) {
			char c = word[i];

			if(!tmp->arr[c-'a']) {
				tmp->arr[c-'a'] = new Node();
				count++;
			}
			tmp = tmp->arr[c-'a'];
		}
	}
};

class Solution{	
	public:
		int bruteForce(string s) {

			unordered_set<string> st;
			st.insert("");	
			
			for(int i=0;i<s.size();i++) {

				string str = "";
				for(int j=i;j<s.size();j++) {
					str += s[j];
					st.insert(str);
				}
			}
			return st.size();
		}

		int trieCode(string s) {
			Trie t;
			for(int i=0;i<s.size();i++) {
				t.insert(s, i);
			}
			return t.count;
		}
		int countDistinctSubstring(string s){
			return trieCode(s);
		}
};