class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
       vector<int> prev(n2+1, 0), curr(n2+1, 0);
        for(int i1=1;i1<=n1;i1++) {
            for(int i2=1;i2<=n2;i2++) {
                if(word1[i1-1] == word2[i2-1]) {
                    curr[i2] = prev[i2-1]+1;
                } else {
                    curr[i2] = max(curr[i2-1], prev[i2]);
                }
            }
            prev = curr;
        }
        return n1+n2 - 2*prev[n2];
    }
};