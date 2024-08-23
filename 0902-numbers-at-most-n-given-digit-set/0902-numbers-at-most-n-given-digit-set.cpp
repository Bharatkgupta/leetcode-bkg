class Solution {
public:
    int count(vector<string>& digits, string ns, int idx, int prevlimit, int isUsed, vector<vector<vector<int>>>& dp) {
        if(idx == ns.length()) {
            return isUsed;
        }
        if(dp[idx][prevlimit][isUsed] != -1) {
            return dp[idx][prevlimit][isUsed];
        }
        int limit;
        if(prevlimit) {
            limit = ns[idx]-'0';
        } else {
            limit = 9;
        }
        int c=0;
        if(!isUsed) {
            c += count(digits, ns, idx+1, 0, 0, dp);
        }
        for(int i = 0; i<digits.size(); i++) {
            int num = digits[i][0] - '0';
            if(num > limit) {
                break;
            }
            int nlimit = num == limit && prevlimit;
            c += count(digits, ns, idx+1, nlimit, 1, dp);
        }
        return dp[idx][prevlimit][isUsed] = c;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string ns = to_string(n);
        vector<vector<vector<int>>> dp(10, vector<vector<int>> (2, vector<int> (2, -1)));
        return count(digits, ns, 0, 1, 0, dp);
    }
};