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
    void reorderList(ListNode* head) {
       if (!head || !head->next) return;

       // 1. Find the middle of the linked list
       ListNode* slow = head;
       ListNode* fast = head;
       while (fast->next && fast->next->next) {
        slow = slow->next;
        fast =fast->next->next;
       } 

       // 2. Reverse the second half of the list
       ListNode* prev = nullptr;
       ListNode* curr = slow->next;
       slow->next = nullptr; // Split the list into two halves

       while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
       }

       // 3. Merge the two halves alternatingly
       ListNode* first = head;
       ListNode* second = prev;

       while (second) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
       }
    }
};
