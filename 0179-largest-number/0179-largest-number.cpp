class Solution {
    static bool comp(string a, string b) {
        int an = a.length(), bn = b.length();
        for(int i=0;i<min(an, bn);i++) {
            if(a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        if(an > bn) {
            return comp(a.substr(bn), b);
        } else if(bn > an) {
            return comp(a, b.substr(an));
        }
        return true;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numString;
        bool flag = true;
        for(const int& num : nums) {
            if(num != 0) {
                flag = false;
            }
            numString.push_back(to_string(num));
        }
        if(flag) {
            return "0";
        }
        sort(numString.begin(), numString.end(), comp);
        string ans = "";
        for(const string& ns : numString) {
            ans += ns;
        }
        return ans;
    }
};