class Solution {
    int fact[10] = {0};
    int factorial(int n) {
        if(n == 0) {
            return 1;
        }
        if(fact[n] != 0) {
            return fact[n];
        }
        return n*factorial(n-1);
    }
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<bool> used(n,false);
        for(int i=0;i<n;i++) {
            int sum = 0;
            int c = 0;
            while(used[c]) {
                c++;
            }
            while(sum + factorial(n-i-1) < k) {
                sum += factorial(n-i-1);
                c++;
                while(used[c]) {
                    c++;
                }
            }
            k = k - sum;
            ans += ('1'+c);
            used[c] = true;
        }
        return ans;
    }
};