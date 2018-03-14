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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head , *q;
        int count = 0 , m;
        while(p!=NULL) {
            p=p->next;
            ++count;
        }
        m = count-n;
        p = head;
        q= head;
        while(p != NULL&&m>=0&&head!=NULL){
           if(m==0) { /*删除结点为头结点时*/
               head = head->next;
               break;
           }else if(m>1){
               p = p->next;
               --m;
           }else if(m == 1) {
               if(n == 1){/*删除结点为尾结点时*/
                   p->next = NULL;
                   p = p->next;
               }else {
                   q= p->next;
                   p->next = q->next;
                   p = p->next;
                   break;
               }
           }
        }
        return head;
    }
};

/*改进后的两次遍历*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*f = new ListNode(0);
        f->next = head;
        p = head;
        int  count = 0;
        while(p!=NULL) {
            p= p->next;
            count++;
        }
        int  m = count - n;
        p = f;
        while(m>0){
            p = p->next;
            --m;
        }
        p->next = p->next->next;
        return f->next;
        
    }
};

/**
 *一次遍历
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*f = new ListNode(0);
        f->next = head;
        p = f;
        while(n>=0) {
            n--;
            p = p->next;
        }
        head = f;
        while(p!=NULL){
            p = p->next;
            head= head->next;
        }
        head->next = head->next->next;
        return f->next;
       
    }
};