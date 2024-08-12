class Solution {
public:
    int numNodes(int currNode, vector<vector<int>>& adj, vector<bool>& visited, int& goodNodes) {
        visited[currNode] = true;
        int childNodes = -1;
        int sum = 0;
        bool flag = true;
        for(const int& nextNode : adj[currNode]) {
            if(!visited[nextNode]) {
                if(childNodes == -1) {
                    childNodes = numNodes(nextNode, adj, visited, goodNodes);
                    sum += childNodes;
                } else {
                    int newChildNodes = numNodes(nextNode, adj, visited, goodNodes);
                    sum += newChildNodes;
                    flag = flag && childNodes == newChildNodes;
                }
            }
        }
        if(flag) {
            goodNodes++;
        }
        return 1 + sum;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        vector<bool> visited(n, false);
        numNodes(0, adj, visited, ans);
        return ans;
    }
};