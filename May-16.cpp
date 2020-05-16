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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        
        ListNode* newhead1 = head;
        ListNode* newhead2 = head->next;
        ListNode* curr1 = head;
        ListNode* curr2 = head->next;
        
        while(curr1 != NULL && curr2 != NULL)
        {
            ListNode* next1 = curr1->next->next;
            ListNode* next2;
            if(curr2->next != NULL)
                next2 = curr2->next->next;
            else 
                next2 = NULL;
            curr1->next = next1;
            curr2->next = next2;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        curr1 = newhead1;
        while(curr1->next != NULL)
            curr1 = curr1->next;
        curr1->next = newhead2;
        return newhead1;
    }
};