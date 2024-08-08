class Solution {
public:
    int minimumDeleteSum(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<int> prev(l2+1,0), curr(l2+1,0);
        for(int i=1;i<=l2;i++) {
            prev[i] = word2[i-1]+prev[i-1];
        }
        for(int i1=1;i1<=l1;i1++) {
            curr[0] = word1[i1-1]+prev[0];
            for(int i2=1;i2<=l2;i2++) {
                if(word1[i1-1] == word2[i2-1]) {
                    curr[i2] = prev[i2-1];
                } else {
                    curr[i2] = min(word1[i1-1]+prev[i2], word2[i2-1]+curr[i2-1]);
                }
            }
            prev = curr;
        }
        return prev[l2];
    }
};