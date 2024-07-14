class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        for(int i=1;i<n;i++) {
            if(s[i-1] > s[i]) {
                if((s[i-1]%2) == (s[i]%2)) {
                    char temp = s[i];
                    s[i] = s[i-1];
                    s[i-1] = temp;
                    break;   
                }
            }
        }
        return s;
    }
};