class Solution {
public:
    int minAddToMakeValid(string s) {
        int badopen = 0, badclose=0;
        for(const int& bracket : s) {
            if(bracket == '(') {
                badopen++;
            } else {
                if(badopen) {
                    badopen--;
                } else {
                    badclose++;
                }
            }
        }
        return badopen+badclose;
    }
};