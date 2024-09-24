class TrieNode {
public:
    TrieNode* child[10];
};

class Solution {
    int LCP(TrieNode* t1, TrieNode* t2) {
        int mx = 0;
        for(int i=0;i<10;i++) {
            if(t1->child[i] != nullptr && t2->child[i] != nullptr) {
                mx = max(mx, 1+LCP(t1->child[i], t2->child[i]));
            }
        }
        return mx;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode *t1 = new TrieNode(), *t2 = new TrieNode();
        for(const int& num : arr1) {
            string nums = to_string(num);
            TrieNode* temp = t1;
            for(const char& ch : nums) {
                if(temp->child[ch-'0'] == nullptr) {
                    temp->child[ch-'0'] = new TrieNode();
                }
                temp = temp->child[ch-'0'];
            }
        }
        for(const int& num : arr2) {
            string nums = to_string(num);
            TrieNode* temp = t2;
            for(const char& ch : nums) {
                if(temp->child[ch-'0'] == nullptr) {
                    temp->child[ch-'0'] = new TrieNode();
                }
                temp = temp->child[ch-'0'];
            }
        }
        return LCP(t1, t2);
    }
};