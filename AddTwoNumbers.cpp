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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Sum = new ListNode(0);
        ListNode* SumOriginal = Sum;
    
        while(l1!=NULL || l2!=NULL){
            int val1 = (l1==NULL)?0:(l1->val);
            int val2 = (l2==NULL)?0:(l2->val);
            int quotient = (Sum->val + val1 + val2)/10;
            Sum->val = (Sum->val + val1 + val2)%10;
            
            
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
            
            cout<<quotient<<endl;
            if (quotient != 0 || l1 != NULL || l2 != NULL){
                Sum->next = new ListNode(quotient);
                Sum = Sum->next;
            }
            
        }
    
        return SumOriginal;
    }
    
};
