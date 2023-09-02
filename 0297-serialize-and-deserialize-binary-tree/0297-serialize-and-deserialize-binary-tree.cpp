/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* t;
            t = q.front();
            q.pop();
            if(t == NULL)
            {
                s += 'N';
            }
            else
            {
                s += 'S';
                s += to_string(t->val);
                s += 'S';
            }
            if(t!= NULL)
            {
                q.push(t->left);
                q.push(t->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        int n = s.size();
        cout<<s<<"\n";
        queue<TreeNode*> q;
        TreeNode* temp,*root;
        
        int i = 1;
        string str;
        if(s[i] == 'S') i++;
        if(s[0] != 'N')
        {
            str  = "";
            while(i<n && s[i] != 'S')
            {
                str += s[i++];
            }
            // cout<<str<<"\n";
            int a = stoi(str);
            temp = new TreeNode;
            temp->val = a;
            root = temp;
            q.push(temp);
        }
        else
        {
            root = NULL;
        }
        i++;
        while(!q.empty() && i<n)
        {
            TreeNode* t;
            t = q.front();
            q.pop();
            if(s[i] == 'S') i++;
            if(s[i] != 'N')
            {
                str  = "";
                while(i<n && s[i] != 'S')
                {
                    str += s[i++];
                }
                // cout<<str<<"\n";
                int a;
                a = stoi(str);
                temp = new TreeNode;
                temp->val = a;
                temp->left = NULL;
                temp->right = NULL;
                t->left = temp;
                q.push(temp);
            }
            else
            {
                t->left = NULL;
            }
            i++;
            if(s[i] == 'S') i++;
            if(i < n)
            {
                if(s[i] != 'N')
                {
                    str  = "";
                    while(i<n && s[i] != 'S')
                    {
                        str += s[i++];
                    }
                    // cout<<str<<"\n";
                    int  a;
                    a = stoi(str);
                    temp = new TreeNode;
                    temp->val = a;
                    temp->left = NULL;
                    temp->right = NULL;
                    t->right = temp;
                    q.push(temp);
                }
                else
                {
                    t->right = NULL;
                }
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));