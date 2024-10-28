class Solution {
    bool isColorable(vector<vector<int>>& graph, int currNode, vector<int>& color) {
        for(const int& nextNode : graph[currNode]) {
            if(color[nextNode] != -1) {
                if(color[nextNode] == color[currNode]) {
                    return false;
                }
            } else {
                color[nextNode] = color[currNode] == 0 ? 1 : 0;
                if(!isColorable(graph, nextNode, color)) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int numOfNodes = graph.size();
        vector<int> color(numOfNodes, -1);
        for(int node=0;node<numOfNodes;node++) {
            if(color[node] == -1) {
                color[node] = 0;
                if(!isColorable(graph, node, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};