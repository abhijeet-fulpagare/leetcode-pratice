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
    void reorderList(ListNode* head) 
    {
        ListNode* temp = head;

        while(temp && temp->next && temp->next->next)
        {
            ListNode* t = temp;

            ListNode* prev = NULL;
            ListNode* nxt = temp -> next;


            while(t->next != NULL)
            {
                prev =t;
                t= t->next;
            }

            if(prev)
            {
                prev->next = NULL;
                temp->next = t;
                temp = temp->next;

                temp->next = nxt;
                temp = temp->next;
            }
           

        }
        
    }
};