class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        char prev = sentence[n-1];
        bool check = true;
        for(int i=0;i<n;i++) {
            if(check) {
                if(prev != sentence[i]) {
                    return false;
                }
                check = false;
            }
            if(sentence[i] == ' ') {
                prev = sentence[i-1];
                check = true;
            }
        }
        return true;
    }
};