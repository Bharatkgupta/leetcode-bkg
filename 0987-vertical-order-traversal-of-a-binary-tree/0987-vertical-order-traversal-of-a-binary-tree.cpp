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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> vot;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int len = q.size();
            map<int, multiset<int>> localvot;
            while(len--) {
                auto curr = q.front();
                q.pop();
                TreeNode* currNode = curr.first;
                int currCol = curr.second;
                localvot[currCol].insert(currNode->val);
                if(currNode->left) {
                    q.push({currNode->left, currCol-1});
                }
                if(currNode->right) {
                    q.push({currNode->right, currCol+1});
                }
            }
            for(const auto& elem : localvot) {
                int col = elem.first;
                multiset<int> vals = elem.second;
                for(const int& val : vals) {
                    vot[col].push_back(val);
                }
            }
        }
        vector<vector<int>> ans;
        for(const auto& elem : vot) {
            ans.push_back(elem.second);
        }
        return ans;
    }
};