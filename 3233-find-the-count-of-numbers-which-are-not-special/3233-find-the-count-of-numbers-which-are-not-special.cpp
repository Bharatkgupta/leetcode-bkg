class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r), count = 0;
        vector<int> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i*i<=n;i++) {
            if(isPrime[i]) {
                for(int j=i*i;j<=n;j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        int start = sqrt(l);
        if(start*start != l) {
            start+=1;
        }
        for(int sp=start; sp*sp<=r; sp++) {
            if(isPrime[sp]) {
                count++;
            }
        }
        return r-l+1-count;
    }
};