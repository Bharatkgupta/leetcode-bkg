class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        // Initialize the adjacency list to store the graph where adj[i] contains the neighbors of node i
        vector<vector<int>> adj(n);

        // Populate the adjacency list based on the given edges (undirected graph)
        for (const vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Compute the degree of each node (how many neighbors it has)
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) {
            deg[i] = adj[i].size();
        }
        
        // defining custom comparator as lambda expression
        auto comp = [&deg] (int a, int b) {
            return deg[a] < deg[b];
        };
        
        for (int i = 0; i < n; ++i) {
            sort(adj[i].begin(), adj[i].end(), comp);
        }

        // Find the arbitrary root node with the minimal degree (this node will be used as a starting point)
        int root = min_element(deg.begin(), deg.end()) - deg.begin();

        // Start constructing the first row from the root node
        vector<int> path = {root};

        // Track which nodes have been added to the path using the 'seen' array
        vector<bool> seen(n, false);
        seen[root] = true;

        // For each node in the first row, attempt to add neighboring nodes using DFS
        while (true) {
            // Break if we've found another corner
            if (path.size() >= 2 && deg[path.back()] == deg[root]) {
                break;
            }
            int node = path.back();

            // Try to add an unseen neighboring node to the path
            for (int nei : adj[node]) {
                // This condition: `deg[nei] <= deg[root] + 1` is to make sure we add the borders only
                if (!seen[nei] && deg[nei] <= deg[node] + 1) {
                    path.push_back(nei);
                    seen[nei] = true;
                    break;  // Stop after adding one node to the path
                }
            }
        }

        // Determine the number of columns in the grid (C), which is the length of the path
        int C = path.size();

        // Determine the number of rows in the grid (R), which is the total number of nodes divided by the number of columns
        int R = n / C;

        // Initialize the grid layout (2D list) with zeros
        vector<vector<int>> ans(R, vector<int>(C, 0));

        // Assign the path to the first row of the grid
        ans[0] = path;

        // Fill the remaining rows in the grid by connecting each element in the previous row to one of its neighbors
        for (int r = 1; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                // For each column, find an unseen neighbor from the previous row's corresponding node
                for (int nei : adj[ans[r - 1][c]]) {
                    if (!seen[nei]) {
                        ans[r][c] = nei;  // Assign the neighbor to the current cell
                        seen[nei] = true;
                        break;  // Break to optimize performance as there should be only one valid node for this
                    }
                }
            }
        }

        return ans;
    }
};