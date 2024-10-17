class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for(int i=0;i<n;i++) {
            int mxIdx = i;
            for(int j=n-1;j>i;j--) {
                if(s[mxIdx] < s[j]) {
                    mxIdx = j;
                }
            }
            if(mxIdx != i) {
                swap(s[i], s[mxIdx]);
                break;
            }
        }
        return stoi(s);
    }
};