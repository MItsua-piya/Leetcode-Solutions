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
pair<int,int> help(TreeNode*root){
    if (root==nullptr){
        return make_pair(0,0);
    }
    pair<int,int> LI=help(root->left);
     pair<int,int>  RI=help(root->right);
    int currD= RI.second +LI.second;
    int FH=max(LI.second,RI.second)+1;
    int FD=max(currD,max(LI.first,RI.first));
    return make_pair(FD,FH);
}
    int diameterOfBinaryTree(TreeNode* root) {
        return help(root).first;
    }
};