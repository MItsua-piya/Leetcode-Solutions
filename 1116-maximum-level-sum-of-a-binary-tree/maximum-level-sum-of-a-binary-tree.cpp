/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
         int level = 1;
        int answer = 1;
        int sum=INT_MIN;
        while(!q.empty()){
            int size=q.size();
            int currSum=0;
            for(int i=0;i<size;i++){
              TreeNode* currNode=q.front();
              currSum+=currNode->val;
              q.pop();
              if(currNode->right){
                q.push(currNode->right);
              }
               if(currNode->left){
                q.push(currNode->left);
              }

            }
           if(currSum > sum) {
                sum = currSum;
                answer = level;
            }

            level++;
            
        }
        return answer;
    }
};