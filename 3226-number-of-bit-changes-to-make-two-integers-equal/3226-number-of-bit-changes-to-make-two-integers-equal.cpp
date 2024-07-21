class Solution {
public:
    int minChanges(int n, int k) {
        if(k>n) {
            return -1;
        } else if(k==n) {
            return 0;
        } else {
            int ans = 0;
            while(n) {
                if(k%2 == 1 && n%2 == 0) {
                    return -1;
                } else if(k%2 == 0 && n%2 == 1) {
                    ans++;
                }
                k = k/2;
                n = n/2;
            }
            return ans;
        }
    }
};