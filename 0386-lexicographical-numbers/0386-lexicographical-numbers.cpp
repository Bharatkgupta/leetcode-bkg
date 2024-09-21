class Solution {
    void backtracking(int n, int val, bool isFirst, vector<int>& list) {
        for(int i=(isFirst ? 1 : 0);i<=9;i++) {
            int newVal = val*10+i;
            if(newVal>n) {
                break;
            }
            list.push_back(newVal);
            backtracking(n, newVal, false, list);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicoList;
        backtracking(n, 0, true, lexicoList);
        return lexicoList;
    }
};