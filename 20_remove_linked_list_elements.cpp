/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/


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
    ListNode* removeElements(ListNode* head, int val) {
        while (head and head->val == val)
            head = head->next;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->next and temp->next->val == val) {
                ListNode* temp2 = temp->next;
                while (temp2 and temp2->val == val) {
                    temp2 = temp2->next;
                }
                temp->next = temp2;
            }
            temp = temp->next;
        }
        return head;
    }
};