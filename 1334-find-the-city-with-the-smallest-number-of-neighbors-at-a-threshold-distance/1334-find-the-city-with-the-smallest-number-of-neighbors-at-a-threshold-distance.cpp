class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n, vector<int> (n, INT_MAX));
        for(int i=0;i<n;i++) {
            d[i][i] = 0;
        }
        for(const auto& edge : edges) {
            d[edge[0]][edge[1]] = edge[2];
            d[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(d[i][k] != INT_MAX && d[k][j] != INT_MAX) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
                    }
                }
            }
        }
        int ans = n-1, minCount = INT_MAX;
        for(int i=n-1;i>=0;i--) {
            int count = -1;
            for(int j=0;j<n;j++) {
                if(d[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if(count < minCount) {
                ans = i;
                minCount = count;
            }
        }
        return ans;
    }
};