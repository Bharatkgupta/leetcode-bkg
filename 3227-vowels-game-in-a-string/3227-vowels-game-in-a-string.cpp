class Solution {
public:
    bool doesAliceWin(string s) {
        for(const char& ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }
        return false;
    }
};