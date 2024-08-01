class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<int> prev(l2+1), curr(l2+1);
        for(int i2=0;i2<=l2;i2++) {
            prev[i2] = i2;
        }
        for(int i1=1;i1<=l1;i1++) {
            curr[0] = i1;
            for(int i2=1;i2<=l2;i2++) {
                if(word1[i1-1] == word2[i2-1]) {
                    curr[i2] = prev[i2-1];
                } else {
                    curr[i2] = 1+min(prev[i2], min(prev[i2-1], curr[i2-1]));
                }
            }
            prev=curr;
        }
        return prev[l2];
    }
};