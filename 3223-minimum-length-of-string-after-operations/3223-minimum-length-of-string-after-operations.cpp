class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(const char& ch : s) {
            freq[ch - 'a']++;
        }
        int ans = 0;
        for(int i=0;i<26;i++) {
            if(!freq[i]) {
                continue;
            }
            if(freq[i]%2) {
                ans++;
            } else {
                ans = ans + 2;
            }
        }
        return ans;
    }
};