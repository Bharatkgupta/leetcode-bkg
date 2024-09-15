class TrieNode {
public:
    TrieNode* node[26];
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        TrieNode* root = new TrieNode();
        for(const string& word : words) {
            TrieNode* temp = root;
            int n = word.length();
            for(int i=0;i<n;i++) {
                if(temp->node[word[i]-'a'] == nullptr) {
                    temp->node[word[i]-'a'] = new TrieNode();
                }
                temp = temp->node[word[i]-'a'];
            }
        }

        int n = target.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;  
        
        for (int i = n - 1; i >= 0; --i) {
            TrieNode* curr = root;
    
            for (int j = i; j < n; ++j) {
                int key = target[j] - 'a';
                if (!curr->node[key]) {
                    break; 
                }
                curr = curr->node[key];
                
                if (dp[j + 1] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }
        
        return dp[0] == INT_MAX ? -1 : dp[0];
    }
};