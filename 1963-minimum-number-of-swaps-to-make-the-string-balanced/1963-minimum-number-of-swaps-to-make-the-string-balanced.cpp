class Solution {
public:
    int minSwaps(string s) {
        int nOpen = 0, nClose = 0;
        for(const char& ch : s) {
            if(ch == '[') {
                nOpen++;
            } else {
                if(nOpen > 0) {
                    nOpen--;
                } else {
                    nClose++;
                }
            }
        }
        return ceil((float) nClose/2);
    }
};
