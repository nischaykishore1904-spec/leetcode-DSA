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
    int len(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;
        k = k % len(head);
        for(int i = 1; i <= k; i++){
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp -> next != NULL){
                prev = temp;
                temp = temp -> next;
            }
            temp -> next = head;
            head = temp;
            prev -> next = NULL;
        }
        return head;
    }
};