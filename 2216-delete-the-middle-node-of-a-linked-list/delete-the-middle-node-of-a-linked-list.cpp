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
            count++;
            temp = temp -> next;
        }
        return count;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return head;
        if(head -> next == NULL) return NULL;
        int size_LL = size(head);
        int mid = size_LL/2;

        ListNode* temp = head;
        for(int i = 0; i < mid-1; i++){
            temp = temp -> next;
        }
        ListNode* garbage = temp -> next;
        temp -> next = temp -> next -> next;
        delete garbage;
        return head;
    }
};