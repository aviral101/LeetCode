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
    long long widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        long long ans = 0,min,max;
        q.push(make_pair(root,1));
        while(q.size() != 0 )
        {
            vector<pair<TreeNode*,long long>> v;
            min = 100000000000;
            max = -100000000000;
            while(q.size() != 0)
            {
                v.push_back(q.front());
                q.pop();
            }
            int n = v.size();
            int c = 0;
            int cmin = v[0].second;
            // cout<<"it : ";
            for(int i = 0; i<n; i++)
            {
                TreeNode *t;
                t = v[i].first;
                long long x = v[i].second ;
                x = x - cmin + 1;
                // cout<<x<<" ";
                if(min > x) min = x;
                if(max < x) max = x;
                // cout<<max<<"\n";
                
                if(t->left != NULL)
                    q.push(make_pair(t->left,2*x - 1));
                if(t->right != NULL)
                    q.push(make_pair(t->right, 2*x));
            }
            // cout<<"\n";
            if(ans < max - min + 1) ans = max - min + 1;
        }
        // cout<<ans;
        return ans;
    }
};