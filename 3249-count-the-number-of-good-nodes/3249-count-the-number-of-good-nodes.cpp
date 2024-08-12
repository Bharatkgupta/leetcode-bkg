class Solution {
public:
    int numNodes(int currNode, vector<vector<int>>& adj, vector<bool>& visited, int& goodNodes) {
        visited[currNode] = true;
        vector<int> childNodes;
        for(const int& nextNode : adj[currNode]) {
            if(!visited[nextNode]) {
                childNodes.push_back(numNodes(nextNode, adj, visited, goodNodes));
            }
        }
        int sum = 0;
        if(childNodes.empty()) {
            goodNodes++;
        } else {
            int val = childNodes[0];
            bool flag = true;
            for(int i=0;i<childNodes.size();i++) {
                sum += childNodes[i];
                if(val != childNodes[i]) {
                    flag = false;
                }
            }
            if(flag) {
                goodNodes++;
            }
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