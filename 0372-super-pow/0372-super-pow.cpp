int mod = 1337;

class Solution {
    int mediumPow(int a, int b) {
        if(b == 0) {
            return 1;
        }
        if(b%2 == 0) {
            return mediumPow((a*a)%mod, b/2)%mod;
        } else {
            return (a*mediumPow((a*a)%mod, b/2))%mod;
        }
    }
public:
    int superPow(int a, vector<int>& b) {
        int result = 1, n = b.size();
        a = a%mod;
        for(int i = n-1; i>=0;i--) {
            result = (result*mediumPow(a, b[i]))%mod;
            a = mediumPow(a, 10)%mod;
        }
        return result;
    }
};