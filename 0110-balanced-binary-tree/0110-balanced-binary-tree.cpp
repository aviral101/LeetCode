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
    bool c = true;
    int check(TreeNode* root)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(root == NULL) return 0;
        int a = check(root->left);
        int b = check(root->right);
        // cout<<a<<" "<<b<<" "<<root->val<<"\n";
        if(a-b <= -2 || a-b >= 2)
        {
            c = false;
            // cout<<"triggered\n";
        }
        return (a>b)? a+1 : b+1;
    }
    bool isBalanced(TreeNode* root) {
        check(root);
        return c;
    }
};