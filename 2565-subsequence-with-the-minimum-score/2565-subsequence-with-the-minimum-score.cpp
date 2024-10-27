class Solution {
public:
    int minimumScore(string s, string t) {
        int sn = s.size(), tn = t.size();
        vector<int> prefixSub(tn, -1), suffixSub(tn, -1);
        int si = 0, ti = 0;
        while(si<sn && ti<tn) {
            if(s[si] == t[ti]) {
                prefixSub[ti] = si;
                ti++;
            }
            si++;
        }
        si = sn-1; ti = tn-1;
        while(si>=0 && ti>=0) {
            if(s[si] == t[ti]) {
                suffixSub[ti] = si;
                ti--;
            }
            si--;
        }
        suffixSub.push_back(sn);
        int l=-1, r=0, mn = INT_MAX;
        while(r<=tn) {
            if(suffixSub[r] == -1) {
                r++;
                continue;
            }
            while(l<r-1 && prefixSub[l+1] != -1 && prefixSub[l+1] < suffixSub[r]) {
                l++;
            }
            mn = min(mn, r-l-1);
            r++;
        }
        return mn;
    }
};