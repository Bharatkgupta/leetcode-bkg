class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a copy of the array to avoid modifying the original
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Use an unordered map for efficient rank lookup
        unordered_map<int, int> rankMap;

        int rank = 1;
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }

        // Assign ranks to the original array
        for (int& num : arr) {
            num = rankMap[num];
        }

        return arr;
    }
};