class TrieNode {
public:
    TrieNode* alphabet[26] = {nullptr};
    bool end = false;
};

class Trie {
    TrieNode* head;
public:
    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = head;
        for(const auto c:word) {
            if(temp->alphabet[c-'a'] == nullptr) {
                temp->alphabet[c-'a'] = new TrieNode();
            }
            temp = temp->alphabet[c-'a'];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = head;
        for(const auto c:word) {
            if(temp->alphabet[c-'a']){
                temp = temp->alphabet[c-'a'];
            } else {
                return false;
            }
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = head;
        for(const auto c:prefix) {
            if(temp->alphabet[c-'a']){
                temp = temp->alphabet[c-'a'];
            } else {
                return false;
            }
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