class Solution {
    int recur(const string& source, const string& pattern, const vector<int>& targetIndices, 
              int is, int ip, int it, int n, int m, int t, vector<vector<int>>& dp) {
        if (ip == m) {  // Base case: when pattern is fully matched
            return t - it;
        }
        if (is == n) {  // Base case: source string is exhausted
            return INT_MIN;
        }
        if (dp[is][ip] != -1) {  // Return already computed result
            return dp[is][ip];
        }

        int result;
        bool isTargetIndex = (it < t && is == targetIndices[it]);

        // Case 1: Characters match at source[is] and pattern[ip]
        if (source[is] == pattern[ip]) {
            if (isTargetIndex) {
                // Either keep the character or skip it
                result = max(1 + recur(source, pattern, targetIndices, is + 1, ip, it + 1, n, m, t, dp),
                             recur(source, pattern, targetIndices, is + 1, ip + 1, it + 1, n, m, t, dp));
            } else {
                // Move both the source and pattern forward
                result = recur(source, pattern, targetIndices, is + 1, ip + 1, it, n, m, t, dp);
            }
        } 
        // Case 2: Characters do not match
        else {
            if (isTargetIndex) {
                // Skip the current character in the source (increase removal count)
                result = 1 + recur(source, pattern, targetIndices, is + 1, ip, it + 1, n, m, t, dp);
            } else {
                // Move only the source pointer forward
                result = recur(source, pattern, targetIndices, is + 1, ip, it, n, m, t, dp);
            }
        }

        dp[is][ip] = result;  // Memoize the result
        return result;
    }

public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        int m = pattern.size();
        int t = targetIndices.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));  // DP table
        return recur(source, pattern, targetIndices, 0, 0, 0, n, m, t, dp);
    }
};