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
    TreeNode* t;
    void preorder(TreeNode* root)
    {
        if(root == NULL) return;
        if(t == NULL) t = root;
        else
        {
            t->left = root;
            t = t->left;
        }
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        t = NULL;
        preorder(root);
        t = root;
        while(t!= NULL)
        {
            t->right = t->left;
            t->left = NULL;
            t = t->right;
        }
        return;
    }
};