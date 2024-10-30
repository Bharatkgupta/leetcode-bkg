class Solution {
    void cdfs(vector<vector<int>>& adjList, int currNode, int prevNode, int time, vector<int>& timeIn, vector<int>& low, vector<vector<int>>& criticalEdges) {
        timeIn[currNode] = time;
        low[currNode] = time;
        for(const int& nextNode : adjList[currNode]) {
            if(nextNode != prevNode) {
                if(timeIn[nextNode] == -1) {
                    cdfs(adjList, nextNode, currNode, time+1, timeIn, low, criticalEdges);
                }
                low[currNode] = min(low[currNode], low[nextNode]);
            }
        }
        if(prevNode != -1 && timeIn[prevNode] < low[currNode]) {
            criticalEdges.push_back({prevNode, currNode});
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(const auto& connection : connections) {
            adjList[connection[0]].push_back(connection[1]);
            adjList[connection[1]].push_back(connection[0]);
        }
        vector<int> timeIn(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> criticalConnections;
        cdfs(adjList, 0, -1, 0, timeIn, low, criticalConnections);
        return criticalConnections;
    }
};