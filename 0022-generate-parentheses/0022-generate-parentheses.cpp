class Solution {
    void gp(int opening, int closing, string curr, vector<string>& ans) {
        if(opening < 0 || closing < 0) {
            return;
        }
        if(opening == 0 && closing == 0) {
            ans.push_back(curr);
            return;
        }
        gp(opening-1, closing+1, curr+'(', ans);
        gp(opening, closing-1, curr+')', ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gp(n,0,"",ans);
        return ans;
    }
};