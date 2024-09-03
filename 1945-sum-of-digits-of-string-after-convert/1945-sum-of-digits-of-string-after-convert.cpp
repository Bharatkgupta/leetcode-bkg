class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(int i=0;i<s.size();i++) {
            int integer = s[i] - 'a' + 1;
            int isum = integer%10 + (integer/10)%10;
            sum += isum;
        }
        while(--k) {
            s = to_string(sum);
            int n=s.size();
            sum = 0;
            for(int i=0;i<n;i++) {
                sum += (s[i] - '1' + 1);
            }
        }
        return sum;
    }
};