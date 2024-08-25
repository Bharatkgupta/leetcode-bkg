class Solution {
public:
    int MS(vector<int>& tasks, int sessionTime, int remaining, int currState, vector<vector<int>>& dp) {
        int n = tasks.size();
        if(currState == ((1<<n) - 1)) {
            return 1;
        }
        if(dp[currState][remaining] != -1) {
            return dp[currState][remaining];
        }
        int mn = INT_MAX;
        for(int i=0;i<n;i++) {
            if((currState & (1<<i)) || tasks[i] > remaining) {
                continue;
            }
            mn = min(mn, MS(tasks, sessionTime, remaining-tasks[i], currState | (1<<i), dp));
        }
        if(mn == INT_MAX) {
            return dp[currState][remaining] = 1+MS(tasks, sessionTime, sessionTime, currState, dp);
        }
        return dp[currState][remaining] = mn;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<vector<int>> dp((1<<n), vector<int> (sessionTime+1, -1));
        return MS(tasks, sessionTime, sessionTime, 0, dp);
    }
};