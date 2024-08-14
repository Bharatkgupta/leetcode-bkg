class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sLen = s.length();
        vector<bool> dp(sLen+1, false);
        dp[0] = true;
        for(int i=0;i<sLen;i++) {
            for(const string& word : wordDict) {
                int len = word.length();
                if(i-len+1 >= 0 && s.substr(i-len+1, len) == word) {
                    dp[i+1] = dp[i-len+1];
                }
                if(dp[i+1]) {
                    break;
                }
            }
        }
        return dp[sLen];
    }
};