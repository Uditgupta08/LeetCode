class TrieNode {
public:
    char data;
    TrieNode* children[26]; // 26 LETTERS
    bool isTerminal;
    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL; // EMPTY FOR STARTING
        }
        isTerminal = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode('\0'); }

    void helperInsert(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int ind = word[0] - 'a';
        TrieNode* child;

        // CURR CHAR IS PRESENT
        if (root->children[ind] != NULL) {
            child = root->children[ind];
        }
        // ABSENT CASE
        else {
            child = new TrieNode(word[0]);
            root->children[ind] = child;
        }
        helperInsert(child, word.substr(1));
    }
    void insert(string word) { helperInsert(root, word); }

    bool helperSearch(TrieNode* root, string word) {
        if (word.size() == 0) {
            return root->isTerminal;
        }

        int ind = word[0] - 'a';
        TrieNode* child;
        if (root->children[ind] != NULL) {
            child = root->children[ind];
        } else {
            return false;
        }
        return helperSearch(child, word.substr(1));
    }
    bool search(string word) { return helperSearch(root, word); }

    bool helperPrefix(TrieNode* root, string prefix) {
        if (prefix.size() == 0) {
            return true;
        }
        int ind = prefix[0] - 'a';
        TrieNode* child;
        if (root->children[ind] != NULL) {
            child = root->children[ind];
        } else {
            return false;
        }
        return helperPrefix(child, prefix.substr(1));
    }
    bool startsWith(string prefix) { return helperPrefix(root, prefix); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */