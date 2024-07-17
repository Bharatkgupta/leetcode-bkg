class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ig=0, is=0, ans=0;;
        while(ig<g.size() && is<s.size()) {
            if(g[ig] <= s[is]) {
                ans++;
                ig++;
            }
            is++;
        }
        return ans;
    }
};