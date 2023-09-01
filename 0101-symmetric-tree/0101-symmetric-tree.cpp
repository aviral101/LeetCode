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
    bool ans = true;
    void find(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL) return;
        else if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))
        {
            ans = false;
            return;
        }
        if(root1->val != root2->val)
        {
            ans = false;
            return;
        }
        find(root1->left,root2->right);
        find(root1->right,root2->left);
        return;
    }
    bool isSymmetric(TreeNode* root) {
        find(root->left,root->right);
        return ans;
    }
};