class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (string word : words) words_set.insert(word);
        vector<string> res;
    
        for (string word : words) {
            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 0; i < n; i++) {
                for (int j = i; j >= 0; j--) {
                    if(dp[j] && i-j+1 < n) {
                        dp[i+1] = dp[i+1] || (words_set.find(word.substr(j, i-j+1)) != words_set.end());
                    }
                }
            }
            if (dp[n]) {
                res.push_back(word);
            }
        }
        return res;
    }
};