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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *parent = nullptr, *currNode = root;
        vector<int> inorder;
        while(currNode) {
            if(currNode->left == nullptr) {
                inorder.push_back(currNode->val);
                parent = currNode;
                currNode = currNode->right;
            } else {
                TreeNode* temp = currNode->left;
                while(temp->right) {
                    temp = temp->right;
                }
                temp->right = currNode;
                parent = currNode;
                currNode = currNode->left;
                parent->left = nullptr;
            }
        }
        return inorder;
    }
};