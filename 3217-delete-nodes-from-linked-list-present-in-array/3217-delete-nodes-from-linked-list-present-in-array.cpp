/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* ans = new ListNode();
        ListNode* prev = ans;
        ans->next = head;
        while(head) {
            if(numSet.find(head->val) != numSet.end()) {
                prev->next = head->next;
                head = head->next;
                continue;
            }
            prev = head;
            head = head->next;
        }
        return ans->next;
    }
};