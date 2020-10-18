class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new Node();
        head->isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = head;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                // 不存在，插入字符
                Node* n = new Node();
                n->c = c;
                node->children[c] = n;
            }
            node = node->children[c];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = head;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = head;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
private:
    struct Node {
        char c;
        bool isWord;
        unordered_map<char, Node*> children;
    };

    Node* head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
