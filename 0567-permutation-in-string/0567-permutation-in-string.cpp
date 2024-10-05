class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1 > l2) {
            return false;
        }
        vector<int> memory(26, 0);
        for(const char& ch : s1) {
            memory[ch - 'a']++;
        }
        int i=0;
        for(i=0;i<l1;i++) {
            memory[s2[i] - 'a']--;
        }
        bool flag = true;
        for(int j=0;j<26;j++) {
            if(memory[j] != 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            return true;
        }
        for(;i<l2;i++) {
            memory[s2[i-l1] - 'a']++;
            memory[s2[i] - 'a']--;
            bool flag = true;
            for(int j=0;j<26;j++) {
                if(memory[j] != 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                return true;
            }
        }
        return false;
    }
};