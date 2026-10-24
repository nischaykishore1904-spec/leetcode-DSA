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
    int sizeLL(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* temp = head;

        int sizeOfLL = sizeLL(head);
        int mid = sizeOfLL/2;

        for(int i = 0; i < mid; i++){
            temp = temp -> next;
        }
        return temp;
    }
};