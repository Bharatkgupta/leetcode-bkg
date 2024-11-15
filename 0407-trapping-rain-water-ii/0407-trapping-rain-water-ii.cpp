class Solution {
    int d[5] = {1,0,-1,0,1};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size(), water = 0;
        
        vector<vector<bool>> v(m, vector<bool> (n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mnheap;
        
        for(int i=0;i<m;i++) {
            mnheap.push({heightMap[i][0], i, 0});
            v[i][0] = true;
            mnheap.push({heightMap[i][n-1], i, n-1});
            v[i][n-1] = true;
        }
        
        for(int i=0;i<n;i++) {
            mnheap.push({heightMap[0][i], 0, i});
            v[0][i] = true;
            mnheap.push({heightMap[m-1][i], m-1, i});
            v[m-1][i] = true;
        }
        
        while(!mnheap.empty()) {
            auto currCell = mnheap.top();
            mnheap.pop();
            
            int h = currCell[0], x = currCell[1], y = currCell[2];
            
            for(int i=0;i<4;i++) {
                int nx = x+d[i], ny = y+d[i+1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !v[nx][ny]) {
                    v[nx][ny] = true;
                    if(heightMap[nx][ny] < h) {
                        water += h - heightMap[nx][ny];
                        mnheap.push({h, nx, ny});
                    } else {
                        mnheap.push({heightMap[nx][ny], nx, ny});
                    }
                }
            }
        }
        return water;
    }
};