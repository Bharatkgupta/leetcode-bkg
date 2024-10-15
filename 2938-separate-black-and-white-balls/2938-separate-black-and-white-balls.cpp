class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size(), p = 0; 
        long long cnt=0;
        for(int i=0;i<n;i++) {
            if(s[i] == '0') {
                swap(s[i], s[p]);
                p++;
                cnt += (i-p+1);
            }
        }
        return cnt;
    }
};