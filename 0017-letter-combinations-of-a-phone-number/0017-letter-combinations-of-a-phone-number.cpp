class Solution {
    vector<string> numtoletter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void lc(string digits, int i, vector<string>& ans, string str) {
        if(i == digits.length()) {
            ans.push_back(str);
            return;
        }
        int ithnum = digits[i]-'0';
        for(int j=0;j<numtoletter[ithnum].length(); j++) {
            lc(digits, i+1, ans, str+numtoletter[ithnum][j]);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) {
            return ans;
        }
        lc(digits, 0, ans, "");
        return ans;
    }
};