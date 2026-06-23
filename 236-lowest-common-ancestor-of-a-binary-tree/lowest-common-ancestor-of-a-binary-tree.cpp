/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool Road(TreeNode* root, TreeNode* a,vector<TreeNode* >&path){
    if(root==nullptr) return false;
       path.push_back(root);
    if(root->val==a->val) return true;
 
    if(Road(root->left,a,path)|| Road(root->right,a,path)){
        return true;
    }
    path.pop_back();
    return false;

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        vector<TreeNode* >path1;
        vector<TreeNode* >path2;
        Road(root,p,path1);
        Road(root,q,path2);
        TreeNode*  lca=nullptr;
        for(int i=0,j=0;i<path1.size()&& j<path2.size();i++,j++){
            if(path1[i]->val!=path2[j]->val){
             break;
            }
            lca=path1[i];
        }
return lca;
    }
};