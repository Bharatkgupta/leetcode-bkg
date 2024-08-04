class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++) {
            adj[i].push_back(i+1);
        }
        vector<int> ans;
        for(const auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            int level = 0;
            vector<bool> v(n, false);
            queue<int> que;
            que.push(0);
            v[0] = true;
            while(!que.empty()) {
                int len = que.size();
                for(int i=0;i<len;i++) {
                    int curr = que.front();
                    que.pop();
                    if(curr == n-1) {
                        ans.push_back(level);
                        break;
                    }
                    for(const int& next : adj[curr]) {
                        if(!v[next]) {
                            v[next] = true;
                            que.push(next);
                        }
                    }
                }
                level++;
            }
        }
        return ans;
    }
};