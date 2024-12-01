class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for(const int& num : arr) {
            if(seen.find(num*2) != seen.end()) {
                return true;
            }
            int half = num/2;
            if(half*2 == num && seen.find(half) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};