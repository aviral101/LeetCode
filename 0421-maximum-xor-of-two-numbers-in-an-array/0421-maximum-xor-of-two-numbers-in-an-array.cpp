struct Node{
    Node* bit[2];
    bool flag = false;
    bool check(int i)
    {
        if(bit[i] != NULL) return true;
        else return false;
    }
    void put(int i, Node* node)
    {
        bit[i] = node;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Node* root = new Node();
        Node* temp = root;
        for(int i = 0; i<n; i++)
        {
            temp = root;
            bitset<32> b(nums[i]);
            for(int j = 31; j>=0; j--)
            {
                // cout<<b[j]<<" ";
                if(!temp->check(b[j]))
                {
                    temp->put(b[j], new Node());
                }
                temp = temp->bit[b[j]];
            }
            // cout<<"\n";
        }
        int ma = 0;
        for(int i = 0; i<n; i++)
        {
            bitset<32> b(nums[i]), a(0);
            temp = root;
            for(int j = 31; j>=0; j--)
            {
                if(b[j] == 1 && temp->check(0))
                {
                    a = (a << 1) | bitset<32>(0);
                    temp = temp->bit[0];
                }
                else if(b[j] == 0 && temp->check(1))
                {
                    // cout<<"fsdfs\n";
                    a = (a<<1) | bitset<32>(1);
                    temp = temp->bit[1];
                }
                else
                {
                    a = (a<<1) | bitset<32>(b[j]);
                    temp = temp->bit[b[j]];
                }
            }
            // cout<<a.to_ulong()<<"\n";
            b = a ^ b;
            ma = max(ma, (int)(b.to_ulong()));
        }
        return ma;
    }
};