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
    ListNode* mergeTwoLists(ListNode* i, ListNode* j) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
         while(i!=nullptr&& j!=nullptr){
          if(i->val <= j->val){
            tail->next=i;
            i=i->next;

          }else{
             tail->next=j;
             j=j->next;
          }
          tail = tail->next;
         }
         while(i!=nullptr){
             tail->next=i;
            i=i->next;
            tail = tail->next;
         }
         while(j!=nullptr){
            tail->next=j;
            j=j->next;
            tail = tail->next;
         }
return dummy.next;
    }
};