class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i, j=0, n = sentence.size(), cnt = 0;
        for(i=0;i<n;i++) {
            if(sentence[i] == searchWord[j]) {
                j++;
                if(j == searchWord.size()) {
                    return cnt+1;
                }
            } else {
                while(i<n && sentence[i] != ' ') i++;
                j = 0;
                cnt++;
            }
        }
        return -1;
    }
};