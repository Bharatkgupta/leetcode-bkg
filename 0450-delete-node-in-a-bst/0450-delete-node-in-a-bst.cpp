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
    TreeNode* findAndRemove(TreeNode* root, int key) {
        if(root == nullptr) {
            return nullptr;
        }
        if(root->val == key) {
            if(root->left == nullptr && root->right == nullptr) {
                return nullptr;
            } else if(root->left == nullptr) {
                return root->right;
            } else if(root->right == nullptr) {
                return root->left;
            }
            
            TreeNode* temp = root->right;
            
            while(temp->left) temp = temp->left;
            
            temp->left = root->left;
            
            return root->right;
        }
        
        root->left = findAndRemove(root->left, key);
        root->right = findAndRemove(root->right, key);
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return findAndRemove(root, key);
    }
};