// https://leetcode.com/problems/palindrome-linked-list/submissions/
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

ListNode *rev(ListNode *head){
    ListNode *res = new ListNode(-1);
    while(head != NULL){
        ListNode *temp = res -> next;
        res -> next = head;
        head = head -> next;
        res -> next -> next = temp;
    }
    
    
    return res -> next;
}


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        
        // if(fast  == NULL) slow = slow -> next;
        
        slow -> next = rev(slow -> next);
        slow = slow -> next;
        // while(head != NULL){
        //     cout<<head-> val<<' ';
        //     head = head -> next;
        // }
        // return 0;
        while(slow != NULL){
            if(slow -> val != head -> val){
                return 0;
            }
            slow = slow -> next;
            head = head -> next;
        }
        
        return 1;
        
    }
};