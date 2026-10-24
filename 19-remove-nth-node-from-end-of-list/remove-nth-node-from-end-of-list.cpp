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
    int size(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int LL_size = size(head);
        if(head == NULL) return head;
        if(head -> next == NULL && n == 1) return NULL;
        if(n == LL_size){
            return head -> next;
        }

        ListNode* temp = head;
        
        int count = 1;
        while(count < LL_size - n){
            temp = temp -> next;
            count++;
        }
        temp -> next = temp -> next -> next;
        return head;
    }
};