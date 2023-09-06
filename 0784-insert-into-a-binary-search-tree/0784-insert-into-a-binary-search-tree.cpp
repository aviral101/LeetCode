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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp;
        temp = root;
        if(root == NULL)
        {
            root = new TreeNode;
            root->val = val;
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        while(temp != NULL)
        {
            if(val <= temp->val)
            {
                if(temp->left == NULL)
                {
                    TreeNode *t = new TreeNode;
                    t->val = val;
                    t->left = NULL;
                    t->right = NULL;
                    temp->left = t;
                    return root;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if(temp->right == NULL)
                {
                    TreeNode *t = new TreeNode;
                    t->val = val;
                    t->left = NULL;
                    t->right = NULL;
                    temp->right = t;
                    return root;
                }
                else
                    temp = temp->right;
            }
        }
        return root;
    }
};