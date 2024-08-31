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
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, int>> dq;
        dq.push_back({root,0});
        int ans = 0;
        while(!dq.empty()) {
            int len = dq.size();
            ans = max(ans, dq.back().second - dq.front().second + 1);
            for(int i=0;i<len;i++) {
                auto curr = dq.front();
                dq.pop_front();
                TreeNode* currNode = curr.first;
                int idx = curr.second;
                if(currNode->left) {
                    dq.push_back({currNode->left, (long long)2*idx+1});
                }
                if(currNode->right) {
                    dq.push_back({currNode->right, (long long)2*idx+2});
                }
            }
        }
        return ans;
    }
};