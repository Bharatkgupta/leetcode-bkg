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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode *curr = head; 
        while(curr) {
            n++;
            curr = curr->next;
        }
        n = (n+1)/2;
        curr = head;
        while(n--) {
            curr = curr->next;
        }
        ListNode *prev = nullptr;
        while(curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        while(prev && head) {
            if(prev->val != head->val) {
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};