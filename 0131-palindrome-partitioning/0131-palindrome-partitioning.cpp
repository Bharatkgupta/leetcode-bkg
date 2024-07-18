class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start<end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void backtrackPartition(string s, int index, vector<string>& temp, vector<vector<string>>& ans) {
        int len = s.length();
        if(index == len) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<len;i++) {
            if(isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i-index+1));
                backtrackPartition(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrackPartition(s, 0, temp, ans);
        return ans;
    }
};