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
 #define pii pair<int, int>
 #define ff first
 #define ss second
class dpNode{
    public:
    pii val;
    dpNode*left;
    dpNode*right;
    dpNode(pii p){
        val = p;
    }
};
class Solution {
public:
    int rob(TreeNode* root) {
        dpNode* nroot = new dpNode({-1, -1});
        dptree(root, nroot);
        return max(recur(root, 0, nroot), recur(root, 1, nroot));
    }
    void dptree(TreeNode*root, dpNode*nroot){
        if(root->left != NULL){
            nroot->left = new dpNode({-1, -1});
            dptree(root->left, nroot->left);
        }
        if(root->right != NULL){
            nroot->right = new dpNode({-1, -1});
            dptree(root->right, nroot->right);
        }
    }
    int recur(TreeNode*node, bool taken, dpNode*dnode){
        if(node == NULL)return 0;
        if(taken && dnode->val.ss != -1)return dnode->val.ss;
        if(!taken && dnode->val.ff != -1 && dnode->val.ss != -1)return max(dnode->val.ff, dnode->val.ss);


        if(taken)return dnode->val.ss = recur(node->left, !taken, dnode->left)+recur(node->right, !taken, dnode->right);


        dnode->val.ff = node->val+recur(node->left, !taken, dnode->left)+recur(node->right, !taken,dnode->right);
        if(dnode->val.ss == -1)dnode->val.ss = recur(node->left, taken, dnode->left)+recur(node->right, taken, dnode->right);

        
        return max(dnode->val.ff, dnode->val.ss);
    }
};
