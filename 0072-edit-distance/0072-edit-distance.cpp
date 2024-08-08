class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> dp(l1+1, vector<int> (l2+1, 0));
        for(int i=0;i<=l1;i++) {
            dp[i][0] = i;
        }
        for(int i=0;i<=l2;i++) {
            dp[0][i] = i;
        }
        for(int i1=1;i1<=l1;i1++) {
            for(int i2=1;i2<=l2;i2++) {
                if(word1[i1-1] == word2[i2-1]) {
                    dp[i1][i2] = dp[i1-1][i2-1];
                } else {
                    dp[i1][i2] = 1+min(dp[i1][i2-1], // insert
                                       min(dp[i1-1][i2], // delete
                                          dp[i1-1][i2-1])); // replace
                }
            }
        }
        return dp[l1][l2];
    }
};