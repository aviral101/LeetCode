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
    int max = -100000;
    int check(TreeNode* root)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL)
        {
            if(max < root->val) max = root->val;
            return root->val;
        }
        int a = check(root->left);
        int b = check(root->right);
        if(root->val < 0)
        {
            if(max < a && a != 0) max = a;
            if(max < b && b!= 0) max = b;
        }
        else
        {
            if(max < a + root->val) max = a + root->val;
            if(max < b + root->val) max = b + root->val;
        }
        if(max < root->val) max = root->val;
        if(max < a + b + root->val) max = a + b + root->val;
        if(a < 0) a = 0;
        if(b < 0) b = 0;
        return (a > b)? a + root->val : b + root->val;
    }
    int maxPathSum(TreeNode* root) {
        check(root);
        return max;
    }
};