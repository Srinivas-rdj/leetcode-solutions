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
    bool hasCycle(ListNode *head) {
         ListNode* p,*q;
       if(head!=NULL){
          p=head;
       if(head->next!=NULL) q=head->next;
           else return false;
       }
       else return false;
        while(p!=q){
            if(p->next==NULL) return false;
            p=p->next;
            if(q->next==NULL||q->next->next==NULL) return false;
            q=q->next->next;
        }
        
        return true;
    }
};