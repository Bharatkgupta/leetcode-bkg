class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        set<char> allowedChar;
        for(const char& ch : allowed) {
            allowedChar.insert(ch);
        }
        for(const string& word : words) {
            bool notFound = false;
            for(const char& ch : word) {
                if(allowedChar.find(ch) == allowedChar.end()) {
                    notFound = true;
                    break;
                }
            }
            if(!notFound) {
                count++;
            }
        }
        return count;
    }
};