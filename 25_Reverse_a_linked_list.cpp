// https://leetcode.com/problems/reverse-linked-list/
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

ListNode* reverse(ListNode *head){
    if(head == nullptr) return head;
    ListNode *curr = head -> next, *prev = head;
    while(curr != nullptr){
        ListNode *temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        head -> next = temp;
        curr = temp;
    }
    
    return prev;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};