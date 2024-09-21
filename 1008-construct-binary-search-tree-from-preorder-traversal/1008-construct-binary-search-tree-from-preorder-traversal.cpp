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
    TreeNode* dvideConquor(vector<int>& preorder, int s, int e) {
        if(s>e) return nullptr;
        TreeNode* root = new TreeNode(preorder[s]);
        int l=s+1,r=e;
        while(l<=r) {
            int m = l+(r-l)/2;
            if(preorder[m] > preorder[s]) {
                if(r == l) {
                    break;
                }
                r = m;
            } else {
                l = m+1;
            }
        }
        root->left = dvideConquor(preorder, s+1, l-1);
        root->right = dvideConquor(preorder, l, e);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dvideConquor(preorder, 0, preorder.size()-1);
    }
};