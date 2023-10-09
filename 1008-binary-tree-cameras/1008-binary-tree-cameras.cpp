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
    int k = 1;
    map<pair<TreeNode*,pair<bool,bool>>,int> d;
    int dp(TreeNode* root, bool tight1, bool tight2)
    {
        if(root == NULL) return 0;
        if(d.find({root,{tight1, tight2}}) != d.end())
            return d[{root,{tight1, tight2}}];
        int a = INT_MAX,b = INT_MAX, c = INT_MAX;
        if(root->val == 0)
            root->val = k++;
        if(tight1 == false && tight2 == false)
        {
            if(root->right == NULL && root->left == NULL) return 1;
            a = dp(root->left, true, false) + dp(root->right, true, false) + 1;
            if(root->left != NULL)
                b = dp(root->left, false, true) + dp(root->right, false, false);
            if(root->right != NULL)
                c = dp(root->left, false, false) + dp(root->right, false, true);
            // cout<<b<<" "<<c<<" bc\n";
            b = min(b,c);
        }
        else if(tight2 == true)
        {
            a = dp(root->left, true, false) + dp(root->right, true, false) + 1;
        }
        else if(tight1 == true && tight2 == false)
        {
            a = dp(root->left, true, false) + dp(root->right, true, false) + 1;
            b = dp(root->left, false, false) + dp(root->right, false, false);
        }
        // cout<<a<<" "<<b<<"\n";
        // cout<<root->val<<" "<<tight1<<" "<<tight2<<" "<<min(a,b)<<"\n";
        return d[{root,{tight1, tight2}}] = min(a,b);
    }
    int minCameraCover(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(root->left == NULL && root->right == NULL) return 1;
        return dp(root, false, false);
    }
};