#include<bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26
struct TrieNode {
    // we will be having a array of pointers and each points to NULL
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
    int wordCount;
    TrieNode(){
        for (int i = 0; i < ALPHABET_SIZE; i++) children[i] = NULL;
         isLeaf = false;
         wordCount = 0;
    }
};

void insert(TrieNode* root, string word){
    TrieNode* curr = root;
    for(int i = 0; i < word.size(); i++){
        int index = word[i] - 'a';
        if(curr->children[index] == NULL){
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isLeaf = true;
}


bool search(TrieNode* root, string key){
    TrieNode* curr = root;
    for (int i = 0; i < key.size(); i++)
    {
        int ind = key[i] - 'a';
        if(curr->children[ind] == NULL){
            return false;
        }
        curr  = curr->children[ind];
    }
    if(curr->isLeaf) return true;
    else return false;
    
}

bool startsWith(TrieNode* root, string key){
    TrieNode* curr = root;
    int count = 0;
    for (int i = 0; i < key.size(); i++)
    {
        int ind = key[i] - 'a';
        if(curr->children[ind] == NULL)  break;
        else count++;
        curr  = curr->children[ind];
    }
    if(count > 0) return true;
    else return false;
    
}


bool delete_key(TrieNode* root, string& word)
{
	TrieNode* currentNode = root;
	TrieNode* lastBranchNode = NULL;
	char lastBrachChar = 'a';

	for (auto c : word) {
		if (currentNode->children[c - 'a'] == NULL) {
			return false;
		}
		else {
			int count = 0;
			for (int i = 0; i < 26; i++) {
				if (currentNode->children[i] != NULL)
					count++;
			}

			if (count > 1) {
				lastBranchNode = currentNode;
				lastBrachChar = c;
			}
			currentNode = currentNode->children[c - 'a'];
		}
	}

	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (currentNode->children[i] != NULL)
			count++;
	}

	// Case 1: The deleted word is a prefix of other words
	// in Trie.
	if (count > 0) {
		currentNode->wordCount--;
		return true;
	}

	// Case 2: The deleted word shares a common prefix with
	// other words in Trie.
	if (lastBranchNode != NULL) {
		lastBranchNode->children[lastBrachChar] = NULL;
		return true;
	}
	// Case 3: The deleted word does not share any common
	// prefix with other words in Trie.
	else {
		root->children[word[0]] = NULL;
		return true;
	}
}


int main()
{
    TrieNode* root = new TrieNode();
    insert(root, "the");
    cout<<startsWith(root, "th");

return 0;
}