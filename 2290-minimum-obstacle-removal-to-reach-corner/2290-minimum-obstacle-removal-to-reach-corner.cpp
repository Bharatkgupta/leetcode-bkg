class Solution {
    int d[5] = {1,0,-1,0,1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        visited[0][0] = true;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int obs = curr[0], x = curr[1], y = curr[2];
            if(x == m-1 && y == n-1) {
                return obs;
            }
            
            for(int i=0;i<4;i++) {
                int nx = x+d[i], ny = y+d[i+1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({obs+grid[nx][ny], nx, ny});
                }
            }
        }
        return 0;
    }
};