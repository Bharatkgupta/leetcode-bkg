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
    TreeNode* dfs(TreeNode* curr, int& start, int& dest, vector<char>& sToR, vector<char>& dToR) {
        if(curr == nullptr) {
            return nullptr;
        }
        TreeNode* left = dfs(curr->left, start, dest, sToR, dToR);
        TreeNode* right = dfs(curr->right, start, dest, sToR, dToR);

        bool cs = curr->val == start;
        bool cd = curr->val == dest;
        bool ls = left != nullptr && left->val == start;
        bool ld = left != nullptr && left->val == dest;
        bool rs = right != nullptr && right->val == start;
        bool rd = right != nullptr && right->val == dest;

        if(ld) {
            dToR.push_back('L');
        }
        if(rd) {
            dToR.push_back('R');
        }
        
        if((cs || ls || rs) && (cd || ld || rd)) {
            return nullptr;
        }
        
        if(cs) {
            sToR.push_back('U');
            return curr;
        } else if(ls) {
            sToR.push_back('U');
            return left;
        } else if(rs) {
            sToR.push_back('U');
            return right;
        }

        if(cd) {
            return curr;
        } else if(ld) {
            return left;
        } else if(rd) {
            return right;
        }
        return nullptr;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> sToR;
        vector<char> dToR;
        dfs(root, startValue, destValue, sToR, dToR);
        string first(sToR.begin(), sToR.end());
        string second(dToR.rbegin(), dToR.rend());
        return first+second;

    }
};