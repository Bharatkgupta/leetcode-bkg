class Solution {
public:
    int climbStairs(int n) {
        int numWays[n+1];
        numWays[0] = 1;
        numWays[1] = 1;
        for(int i=2;i<=n;i++) {
            numWays[i] = numWays[i-1] + numWays[i-2];
        }
        return numWays[n];
    }
};