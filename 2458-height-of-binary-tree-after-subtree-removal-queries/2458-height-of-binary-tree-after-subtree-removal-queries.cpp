/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> height; // Stores height of each node
    unordered_map<int, int> maxHeightWithoutChild; // Max height excluding each child for each node

    // DFS to calculate the height of each node and its subtree's maximum height
    int dfs(TreeNode* node) {
        if (!node) return -1;
        
        int leftHeight = dfs(node->left) + 1;
        int rightHeight = dfs(node->right) + 1;
        
        height[node->val] = max(leftHeight, rightHeight);
        
        return height[node->val];
    }

    // DFS to calculate max height of parent excluding each child
    void calculateMaxHeightWithoutChild(TreeNode* node, int parentHeight, int depth) {
        if (!node) return;
        
        maxHeightWithoutChild[node->val] = parentHeight;
        depth++;
        
        int leftChildHeight = node->left ? height[node->left->val] + depth : depth-1;
        int rightChildHeight = node->right ? height[node->right->val] + depth : depth-1;
        
        calculateMaxHeightWithoutChild(node->left, max(maxHeightWithoutChild[node->val], rightChildHeight), depth);
        calculateMaxHeightWithoutChild(node->right, max(maxHeightWithoutChild[node->val], leftChildHeight), depth);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Step 1: DFS to compute heights
        dfs(root);
        
        // Step 2: DFS to compute max height excluding each child
        calculateMaxHeightWithoutChild(root, 0, 0);
        
        vector<int> result;
        for (int query : queries) {
            result.push_back(maxHeightWithoutChild[query]);
        }
        
        return result;
    }
};
