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
    int max = 0;
    int dia(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int a = dia(root->left);
        int b = dia(root->right);
        if(a + b + 1 > max) max = a+b+1;
        return (a > b)? a+1 : b+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return max-1;
    }
};