class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.size(), cnt=0, i=0, ans=0;
        for(int e=0;e<n;e++) {
            freq[s[e]-'a']++;
            if(freq[s[e]-'a'] == k) {
                cnt++;
            }
            if(cnt > 0) {
                ans += (n-e);
                freq[s[i]-'a']--;
                if(freq[s[i]-'a'] == k-1) {
                    cnt--;
                }
                i++;
                freq[s[e]-'a']--;
                if(freq[s[e]-'a'] == k-1) {
                    cnt--;
                }
                e--;
            }
        }
        return ans;
    }
};