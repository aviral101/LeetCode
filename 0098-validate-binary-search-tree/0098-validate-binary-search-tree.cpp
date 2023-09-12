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
    bool check(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if(root == NULL) return  true;
        if((min == NULL || min->val < root->val) && (max == NULL || max->val > root->val))
        {
            cout<<root->val<<"\n";
            return check(root->left,min,root) && check(root->right,root,max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return check(root, NULL, NULL);
    }
};