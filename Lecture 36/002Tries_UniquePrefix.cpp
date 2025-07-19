#include<iostream>
#include<map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0; // we will update freq from outside
	}

};

class trie {

	node* root; // points to the root node of trie // represents the trie

public :

	trie() {
		root = new node('#');
	}

	// time : O(len of str)

	void insert(const string& str) { // code
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				// cur node has no child node with the value ch
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
			cur->freq++;
		}
		cur->terminal = true;
	}

	// time : O(len of str)

	string shortestUniquePrefix(const string& str) {

		node* cur = root;
		string ans = "";

		for (char ch : str) {
			ans += ch;
			cur = cur->childMap[ch];
			if (cur->freq == 1) {
				return ans;
			}
		}

		return ""; // str has no unique prefix

	}

};

int main() {

	string words[] = {"code", "coder", "coding", "new", "neon"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	for (string word : words) {
		cout << "uniquePrefix(" << word << ") = " << t.shortestUniquePrefix(word) << endl;
	}

	// exp. o/p

	// uniquePrefx(code) = ""
	// uniquePrefx(coder) = "coder"
	// uniquePrefx(coding) = "codi"
	// uniquePrefx(new) = "new"
	// uniquePrefx(neon) = "neo"

	return 0;
}