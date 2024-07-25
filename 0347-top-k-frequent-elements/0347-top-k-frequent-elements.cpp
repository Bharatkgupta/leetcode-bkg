class Solution {
public:
    static bool customComparator(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsFreq;
        for(const int num : nums) {
            if(numsFreq.find(num) == numsFreq.end()) {
                numsFreq[num] = 0;
            }
            numsFreq[num]++;
        }
        vector<pair<int,int>> freqList;
        for(const auto pair : numsFreq) {
            freqList.push_back(pair);
        }
        sort(freqList.begin(),freqList.end(),customComparator);
        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.push_back(freqList[i].first);
        }
        return ans;
    }
};