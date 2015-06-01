#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		this->value = NULL;
	}
	TrieNode(char value) {
		this->value = value;
	}
private:
	char value;
	TrieNode* childs;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {

	}

	// Returns if the word is in the trie.
	bool search(string key) {

	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {

	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");