class TrieNode {
public:
    TrieNode *next[26];
    bool end = false;
};

class Solution {
    int split(string s, int idx, TrieNode *root) {
        int n = s.size();
        if(idx == n) {
            return 0;
        }
        int mx = 0;
        TrieNode *temp = root;
        for(int i=idx;i<n;i++) {
            if(temp->next[s[i]-'a'] == nullptr) {
                temp->next[s[i]-'a'] = new TrieNode();
            }
            temp = temp->next[s[i]-'a'];
            if(temp->end == true) {
                continue;
            }
            temp->end = true;
            mx = max(mx,1+split(s, i+1, root));
            temp->end = false;
        }
        return mx;
    }
public:
    int maxUniqueSplit(string s) {
        TrieNode *root = new TrieNode();
        return split(s, 0, root);
    }
};