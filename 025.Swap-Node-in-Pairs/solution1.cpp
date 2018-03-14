/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode*q =head, *p , *t;
        ListNode *f = new ListNode(0) ;
        f->next = head;
        t =f;
        
        while(q&&(p=q->next)){
            q->next = p->next;
            f->next = p;
            p->next = q;
            f = q;
            q = q->next;
        }
        return t->next;;
    }
};
