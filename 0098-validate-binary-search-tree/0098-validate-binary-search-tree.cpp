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
    pair<int,int>  check(TreeNode* root)
    {
        if(ans == false) return make_pair(0,0);
        pair<int,int> a,b;
        int min, max; 
        if(root->left == NULL && root->right == NULL)
        {
            return make_pair(root->val,root->val);
        }
        else if(root->left != NULL && root->right == NULL)
        {
            a = check(root->left);
            min = a.first;
            max = a.second;
            if(root->val <= max)
            {
                ans = false;
            }
            if(min > root->val) min = root->val;
            if(max < root->val) max = root->val;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            a = check(root->right);
            min = a.first;
            max = a.second;
            if(root->val >=  min)
            {
                ans = false;
            }
            if(min > root->val) min = root->val;
            if(max < root->val) max = root->val;
        }
        else
        {
            a = check(root->left);
            b = check(root->right);
            // cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<"\n";
            min = a.first;
            max = b.second;
            if(root->val <= a.second || root->val >= b.first) ans = false;
            if(min > root->val) min = root->val;
            if(max < root->val) max = root->val;
        }
        return make_pair(min,max);
    }
    bool isValidBST(TreeNode* root) {
        check(root);
        return ans;
    }
};