class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<vector<int>> pq;
        pq.push({0,0,0,health-grid[0][0]});
        vector<vector<int>> minhealth(m, vector<int> (n, 0));
        int d[5] = {1, 0, -1, 0, 1};
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int x = curr[1], y = curr[2], h = curr[3];
            for(int i=0;i<4;i++) {
                int nx = x+d[i], ny = y+d[i+1];
                if(nx == m-1 && ny == n-1 && h-grid[nx][ny] > 0) {
                    return true;
                }
                if(nx>=0 && ny>=0 && nx<m && ny<n && h-grid[nx][ny] > minhealth[nx][ny]) {
                    minhealth[nx][ny] = h-grid[nx][ny];
                    pq.push({nx*nx+ny*ny, nx, ny, h-grid[nx][ny]});
                }
            }
        }
        return false;
    }
};