class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = accumulate(skill.begin(), skill.end(), 0), n = skill.size();
        if(sum%(n/2) != 0) {
            return -1;
        }
        int target = sum/(n/2);
        unordered_map<int,int> freq;
        long long ans = 0;
        for(const int& s : skill) {
            int val = target - s;
            if(freq[val] == 0) {
                freq[s]++;
            } else {
                freq[val]--;
                ans += (s*val);
            }
        }
        for(const auto& kv : freq) {
            if(kv.second != 0) {
                return -1;
            }
        }
        return ans;
    }
};