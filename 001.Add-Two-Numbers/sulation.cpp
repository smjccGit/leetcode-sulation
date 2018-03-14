/**
 * 1. 头指针指向头节点，指针向下移动时，头节点不变。
 * 2. 当该指针不为NULL时，可以向后移动，移动完成后可能指向空结点，但移动这个过程不会报错。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *p = &head ;
        int carry = 0;
        while(l1!=NULL||l2!=NULL) {
            int x = (l1!=NULL) ? l1->val :0;
            int y = (l2!=NULL) ? l2->val :0;
            p->next = new ListNode((x+y+carry)%10);
            p=p->next;
            carry = (x+y+carry)/10;
            if(l1!=NULL) l1= l1->next;
            if(l2!=NULL) l2= l2->next;
            
        }
        if(carry>0) {
            p->next = new ListNode(carry);   
        }
        return head.next;
    }
};
