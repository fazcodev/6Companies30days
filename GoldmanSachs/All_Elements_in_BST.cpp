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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>list1;
        traverse(root1, list1);
        traverse(root2, list1);
        sort(list1.begin(), list1.end());
        return list1;
    }
    void traverse(TreeNode*node, vector<int>&list)
    {
        if(node == NULL)
        {
            return ;
        }
        traverse(node->left, list);
        list.push_back(node->val);
        traverse(node->right, list);
    }
};
