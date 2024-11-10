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
    TreeNode* solveTree(vector<int>& preorder, vector<int>& inorder, int sp, int ep, int si, int ei) {
        if(sp>ep) {
            return nullptr;
        }
        TreeNode* currNode = new TreeNode(preorder[sp]);
        if(sp==ep) {
            return currNode;
        }
        
        int mi = si;
        while(inorder[mi] != preorder[sp]) mi++;
        
        currNode->left = solveTree(preorder, inorder, sp+1, sp+(mi-si), si, mi-1);
        currNode->right = solveTree(preorder, inorder, sp+1+(mi-si), ep, mi+1, ei);
        
        return currNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return solveTree(preorder, inorder, 0, n-1, 0, n-1);
    }
};