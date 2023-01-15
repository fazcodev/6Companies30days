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
class Solution {
public:
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL)return 0;
        recur(root);
        return ans;
    }
    pii recur(TreeNode*node)
    {
        if(node == NULL)return {0, 0};
        pii p = {node->val, 1};
        pii pl = recur(node->left);
        pii pr = recur(node->right);
        p.ff+=(pl.ff+pr.ff);
        p.ss+=(pl.ss+pr.ss);
        int avg = p.ff/p.ss;
        if(avg == node->val)ans++;
        return p;
    }
};
