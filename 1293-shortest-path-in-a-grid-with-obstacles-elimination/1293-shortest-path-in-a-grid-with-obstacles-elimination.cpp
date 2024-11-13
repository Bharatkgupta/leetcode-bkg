class Solution {
    int d[5] = {1,0,-1,0,1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        if(m == 0) {
            return 0;
        }
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0,0,0,grid[0][0]});
        vector<vector<int>> minObsEnc(m, vector<int> (n, INT_MAX));
        minObsEnc[0][0] = grid[0][0];

        while(!q.empty()) {
            auto curr = q.top();
            q.pop();
            int steps = curr[0], x = curr[1], y = curr[2], obsRemoved = curr[3];

            if(x == m-1 && y == n-1) {
                return steps;
            }

            for(int i=0;i<4;i++) {
                int nx = x+d[i], ny = y+d[i+1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && minObsEnc[nx][ny] > obsRemoved) {
                    minObsEnc[nx][ny] = obsRemoved;
                    if(grid[nx][ny] && obsRemoved+1 <= k) {
                        q.push({steps+1, nx, ny, obsRemoved+1});
                    }
                    if(!grid[nx][ny]) {
                        q.push({steps+1, nx, ny, obsRemoved});
                    }
                }
            }
        }
        return -1;
    }
};