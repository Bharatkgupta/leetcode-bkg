class TrieNode {
public:
    TrieNode* child[26];
    bool end;
};

class Solution {
    int EC(string s, int idx, TrieNode* root, vector<int>& dp) {
        int n = s.length();
        if(idx == n) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        int count = 1+EC(s, idx+1, root, dp), i=idx;
        TrieNode* temp = root;
        while(idx < n && temp->child[s[idx]-'a'] != nullptr) {
            temp = temp->child[s[idx]-'a'];
            idx++;
            if(temp->end) {
                count = min(count, EC(s, idx, root, dp));
            }
        }
        return dp[i] = count;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        for(const string& word : dictionary) {
            TrieNode* temp = root;
            for(const char& ch : word) {
                if(temp->child[ch-'a'] == nullptr) {
                    temp->child[ch-'a'] = new TrieNode();
                }
                temp = temp->child[ch-'a'];
            }
            temp->end = true;
        }
        
        vector<int> dp(s.length(), -1);
        
        return EC(s, 0, root, dp);
    }
};