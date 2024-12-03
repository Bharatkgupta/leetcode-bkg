class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int ns = s.size(), isp = 0, nsp = spaces.size();
        string ans = "";
        for(int is = 0;is<ns;is++) {
            if(isp < nsp && is == spaces[isp]) {
                ans += " ";
                isp++;
            }
            ans += s[is];
        }
        return ans;
    }
};