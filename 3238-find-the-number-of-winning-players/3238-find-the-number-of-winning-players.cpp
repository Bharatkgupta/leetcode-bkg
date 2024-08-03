class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> freq(n+1, vector<int> (11, 0));
        for(const auto& p : pick) {
            freq[p[0]][p[1]]++;
        }
        int count = 0;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<11;j++) {
                if(freq[i][j] > i) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};