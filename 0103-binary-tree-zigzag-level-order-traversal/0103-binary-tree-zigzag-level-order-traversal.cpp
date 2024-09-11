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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) {
            return {};
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool isleft = true;
        while(!dq.empty()) {
            int len = dq.size();
            vector<int> subAns;
            while(len--) {
                if(isleft) {
                    TreeNode* curr = dq.front();
                    dq.pop_front();
                    subAns.push_back(curr->val);
                    
                    if(curr->left) {
                        dq.push_back(curr->left);
                    }
                    if(curr->right) {
                        dq.push_back(curr->right);
                    }
                } else {
                    TreeNode* curr = dq.back();
                    dq.pop_back();
                    subAns.push_back(curr->val);
                    
                    if(curr->right) {
                        dq.push_front(curr->right);
                    }
                    if(curr->left) {
                        dq.push_front(curr->left);
                    }
                }
            }
            isleft = !isleft;
            ans.push_back(subAns);
        }
        return ans;
    }
};