class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<vector<int>> sfreq(n+1, vector<int> (3, 0)), efreq(n+1, vector<int> (3, 0));
        for(int i=1;i<=n;i++) {
            for(int j=0;j<3;j++) {
                sfreq[i][j] = sfreq[i-1][j];
            }
            sfreq[i][s[i-1]-'a']++;
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<3;j++) {
                efreq[i][j] = efreq[i+1][j];
            }
            efreq[i][s[i]-'a']++;
        }
                
        int is = 3*k, ie = n, ans = n+1;
        while(is<=ie) {
            int m = is + (ie-is)/2;
            bool isPresent = false;
            for(int i=0;i<=m;i++) {
                int a = sfreq[i][0] + efreq[n-m+i][0];
                int b = sfreq[i][1] + efreq[n-m+i][1];
                int c = sfreq[i][2] + efreq[n-m+i][2];
                
                if(a >= k && b >= k && c >= k) {
                    isPresent = true;
                    break;
                }
            }
            
            if(isPresent) {
                ans = min(ans, m);
                ie = m-1;
            } else {
                is = m+1;
            }
        }
        
        return ans == n+1 ? -1 : ans;
    }
};