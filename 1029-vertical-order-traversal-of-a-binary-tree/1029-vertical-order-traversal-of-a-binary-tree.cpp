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
    int min = 1000000;
    int max = -100000;
    int traverse(TreeNode* root, int i, int h, multiset<vector<int>> &s)
    {
        if(root == NULL) return 0;
        s.insert({i,h,root->val});
        if(i > max) max = i;
        if(i < min) min = i;
        traverse(root->left, i-1, h+1, s);
        traverse(root->right, i+1, h+1, s);
        return 0;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        multiset<vector<int>> s;
        traverse(root,0,0, s);
        vector<vector<int>> ans(-1 * min + max + 1);
        for(auto it = s.begin(); it != s.end(); it++)
        {
            ans[-1 * min + (*it)[0]].push_back((*it)[2]);
        }
        return ans;
    }
};