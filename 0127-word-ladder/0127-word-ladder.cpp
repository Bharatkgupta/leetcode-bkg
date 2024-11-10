class TrieNode {
public:
    TrieNode* child[26];
    bool end;
};

class Trie {
    TrieNode* trie;
public:
    Trie(vector<string>& words) {
        trie = new TrieNode();
        
        for(const string& word : words) {
            TrieNode* temp = trie;
            for(const char& letter : word) {
                if(temp->child[letter-'a'] == nullptr) {
                    temp->child[letter-'a'] = new TrieNode();
                }
                temp = temp->child[letter-'a'];
            }
            temp->end = true;
        }
    }
    
    bool find(string word) {
        TrieNode* temp = trie;
        for(const char& letter : word) {
            if(temp->child[letter-'a'] == nullptr) {
                return false;
            }
            temp = temp->child[letter-'a'];
        }
        if(temp->end == true) {
            temp->end = false;
        } else {
            return false;
        }
        return true;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        Trie trie = Trie(wordList);
        queue<string> q;
        q.push(beginWord);
        int dist = 1, sl = beginWord.size();
        bool found = false;
        while(!q.empty()) {
            int len = q.size();
            for(int i=0;i<len;i++) {
                string curr = q.front();
                q.pop();
                
                for(int j=0;j<sl;j++) {
                    for(char c='a';c<='z';c++) {
                        char temp = curr[j];
                        curr[j] = c;
                        if(temp != c && trie.find(curr)) {
                            q.push(curr);
                            if(curr == endWord) {
                                found=true;
                                break;
                            }
                        }
                        curr[j] = temp;
                    }
                    if(found) {
                        break;
                    }
                }
                if(found) {
                    break;
                }
            }
            dist++;
            if(found) {
                break;
            }
        }
        if(!found) {
            return 0;
        }
        return dist;
    }
};