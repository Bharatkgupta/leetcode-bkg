class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        for(int i1=1;i1<=n1;i1++) {
            for(int i2=1;i2<=n2;i2++) {
                if(str1[i1-1] == str2[i2-1]) {
                    dp[i1][i2] = dp[i1-1][i2-1]+1;
                } else {
                    dp[i1][i2] = max(dp[i1][i2-1], dp[i1-1][i2]);
                }
            }
        }
        int i1=n1, i2=n2;
        string ans = "";
        while(i1>0 && i2>0) {
            if(str1[i1-1] == str2[i2-1]) {
                ans += str1[i1-1];
                i1--;
                i2--;
            } else {
                if(dp[i1-1][i2] > dp[i1][i2-1]) {
                    ans += str1[i1-1];
                    i1--;
                } else {
                    ans += str2[i2-1];
                    i2--;
                }
            }
        }
        while(i1>0) {
            ans += str1[i1-1];
            i1--;
        }
        while(i2>0) {
            ans += str2[i2-1];
            i2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};