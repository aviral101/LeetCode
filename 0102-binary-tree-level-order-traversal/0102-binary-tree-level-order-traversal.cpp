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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != NULL)
            q.push(root);
        vector<vector<int>> ans;
        while(q.size() != 0)
        {
            vector<TreeNode*> temp;
            vector<int> v;
            while(q.size() != 0)
            {
                temp.push_back(q.front());
                q.pop();
            }
            for(int i = 0; i<temp.size(); i++)
            {
                cout<<i<<" "<<temp[i]->val<<"\n";
                v.push_back(temp[i]->val);
                if((temp[i]->left) != NULL)
                    q.push(temp[i]->left);
                if((temp[i]->right) != NULL)
                    q.push(temp[i]->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};