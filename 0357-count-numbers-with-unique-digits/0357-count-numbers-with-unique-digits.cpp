class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }
        int count = 10, itr = 9, product = 9;
        for(int i=2;i<=n;i++) {
            product *= itr;
            itr--;
            count += product;
        }
        return count;
    }
};