class Solution {
public:
    int DC(vector<int>& cookies, int K, int currState, int sum, int mx) {
        int n = cookies.size();
        if(K == 0) {
            if(currState == ((1<<n)-1)) {
                return mx;
            } else {
                return INT_MAX;
            }
        }
        if(currState == ((1<<n)-1)) {
            return INT_MAX;
        }
        int mn = INT_MAX;
        for(int i=0;i<n;i++) {
            if(currState & (1<<i)) {
                continue;
            }
            mn = min(mn, min(DC(cookies, K, currState | (1<<i), sum+cookies[i], max(mx, sum+cookies[i])),
                            DC(cookies, K-1, currState | (1<<i), 0, max(mx, sum+cookies[i]))));
        }
        return mn;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        return DC(cookies, k, 0, 0, 0);
    }
};