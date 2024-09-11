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
    TreeNode* makeBST(vector<int>& nums, int s, int e) {
        if(s>e) {
            return nullptr;
        }
        int m = s + (e-s)/2;
        TreeNode* currNode = new TreeNode(nums[m]);
        currNode->left = makeBST(nums, s, m-1);
        currNode->right = makeBST(nums, m+1, e);
        return currNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size()-1);
    }
};