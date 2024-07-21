class Solution {
public:
    int maxOperations(string s) {
        int count = 0, prev = '1', numOperations = 0;
        for(const char& ch : s) {
            if(ch == '1') {
                if(prev == '0') {
                    numOperations += count;
                }
                count++;
            }
            prev = ch;
        }
        if(prev == '0') {
            numOperations += count;
        }
        return numOperations;
    }
};