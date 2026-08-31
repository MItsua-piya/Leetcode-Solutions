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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        int firstCritical = -1;
        int lastCritical = -1;

        int minDistance = INT_MAX;

        while (curr->next != nullptr) {
            int nextValue = curr->next->val;

        
            bool isCritical =
                (curr->val > prev->val && curr->val > nextValue) ||
                (curr->val < prev->val && curr->val < nextValue);

            if (isCritical) {

    
                if (firstCritical == -1) {
                    firstCritical = index;
                }

            
                if (lastCritical != -1) {
                    minDistance = min(minDistance, index - lastCritical);
                }

                lastCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

       
        if (firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDistance = lastCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};