/*

Implementation of the TRIE data structure to store strings.

Motivation :

Given an array of N strings, and an array of Q queries,
check for each query if it is present in the array or not.

*/

#include<iostream>
#include<map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	map<char, node*> childMap;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
	}

};

class trie {

	node* root; // points to the root node of trie // represents the trie

public :

	trie() {
		root = new node('#');
	}

	// time is proportatial to the len of the string

	// void insert(string str) {
	// 	node* cur = root;
	// 	for (char ch : str) {
	// 		if (cur->childMap.find(ch) == cur->childMap.end()) {
	// 			// cur node has no child node with the value ch
	// 			node* n = new node(ch);
	// 			cur->childMap[ch] = n;
	// 			cur = cur->childMap[ch];
	// 		} else {
	// 			// cur node has a child node with the value ch
	// 			cur = cur->childMap[ch];
	// 		}
	// 	}
	// 	cur->terminal = true;
	// }

	// time : O(len of str)

	void insert(const string& str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				// cur node has no child node with the value ch
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
		}
		cur->terminal = true;
	}

	// time : O(len of str)

	bool search(const string& str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				// cur node has no child node with the value ch
				return false;
			}
			cur = cur->childMap[ch]; // move the cur ptr to the child node with the value ch
		}
		return cur->terminal;
	}
};

int main() {

	string words[] = {"code", "coder", "coding", "block", "blocks", "news"};

	trie t;

	for (string word : words) {
		t.insert(word);
	}

	string queries[] = {"code", "coding", "blocked", "block", "news", "new"};

	for (string query : queries) {
		t.search(query) ? cout << query << " is present" << endl :
		                       cout << query << " is not present" << endl;
	}

	cout << endl;

	return 0;
}