// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
private:
    class Node {
        public:
            bool isEnd;
            unordered_map<char, Node*> edge;
            Node(): isEnd(false) {}
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* iter = root;
        for(char c: word) {
            if(iter->edge.find(c) == iter->edge.end()) {
                iter->edge[c] = new Node();
            }
            iter = iter->edge[c];
        }
        iter->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* iter = root;
        for(char c: word) {
            if(iter->edge.find(c) == iter->edge.end()) {
                return false;
            }
            iter = iter->edge[c];
        }
        return iter->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* iter = root;
        for(char c: prefix) {
            if(iter->edge.find(c) == iter->edge.end()) {
                return false;
            }
            iter = iter->edge[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */