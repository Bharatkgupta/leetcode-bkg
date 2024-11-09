class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monoDec;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ng(n2);
        unordered_map<int,int> loc;
        for(int i=n2-1;i>=0;i--) {
            loc[nums2[i]] = i;
            while(!monoDec.empty() && nums2[i] > monoDec.top()) monoDec.pop();
            if(monoDec.empty()) {
                ng[i] = -1;
            } else {
                ng[i] = monoDec.top();
            }
            monoDec.push(nums2[i]);
        }
        vector<int> ans;
        for(const int& num : nums1) {
            ans.push_back(ng[loc[num]]);
        }
        return ans;
    }
};