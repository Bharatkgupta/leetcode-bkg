class Solution {
public:
    int countOfSubstrings(string word, int k) {
        map<char,int> vowel;
        vowel['a'] = 0;
        vowel['e'] = 0;
        vowel['i'] = 0;
        vowel['o'] = 0;
        vowel['u'] = 0;
        int n = word.size(), s=0, e=0, cnt=0;
        while(e<n) {
            if(vowel.find(word[e]) != vowel.end()) {
                vowel[word[e]]++;
            }
            bool flag = true;
            int count = 0;
            for(const auto& pr : vowel) {
                if(pr.second == 0) {
                    flag = false;
                }
                count += pr.second;
            }
            // cout<<s<<" "<<e<<" "<<count<<endl;
            if(!flag || (e-s+1)-count < k) {
                e++;
                continue;
            }
            if((e-s+1)-count == k) {
                cnt++;
                int ne = e+1;
                while(ne<n && vowel.find(word[ne]) != vowel.end()) {
                    cnt++;
                    ne++;
                }
            }
            if((e-s+1)-count >= k) {
                if(vowel.find(word[s]) != vowel.end()) {
                    vowel[word[s]]--;
                }
                s++;
                if(vowel.find(word[e]) != vowel.end()) {
                    vowel[word[e]]--;
                }
            }
        }
        return cnt;
    }
};