class Solution {
public:
    void backtrackPartition(string s, int index, vector<string>& temp, vector<vector<string>>& ans, vector<vector<bool>>& isPalindrome) {
        int len = s.length();
        if(index == len) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<len;i++) {
            if(isPalindrome[index][i]) {
                temp.push_back(s.substr(index, i-index+1));
                backtrackPartition(s, i+1, temp, ans, isPalindrome);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, false));
        for(int i=0;i<n;i++) {
            int l = i, r = i;
            while(s[r+1] == s[r]) {
                r++;
            }
            for(int j=l;j<=r;j++) {
                for(int k=j;k<=r;k++) {
                    isPalindrome[j][k] = true;
                }
            }
            while(l>=0 && r<n && s[l] == s[r]) {
                isPalindrome[l][r] = true;
                l--;
                r++;
            }
        }
        vector<vector<string>> ans;
        vector<string> temp;
        backtrackPartition(s, 0, temp, ans, isPalindrome);
        return ans;
    }
};