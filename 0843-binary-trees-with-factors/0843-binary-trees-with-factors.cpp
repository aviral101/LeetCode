class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<long long> v(n,1);
        unordered_map<long long, long long> m;
        for(int i = 0; i<n; i++)
        {
            m[arr[i]]++;
        }
        for(int i = 0; i<n; i++)
        {
            int a = arr[i];
            for(int j = 0; j<n; j++)
            {
                if(i != j)
                {
                    if(a % arr[j] == 0 && m.find(a/arr[j]) != m.end())
                    {
                        // cout<<a<<" "<<arr[j]<<" "<<a/arr[j]<<"\n";
                        m[arr[i]] = (m[arr[i]] + (m[arr[j]] * m[a/arr[j]])%1000000007)%1000000007;
                    }

                }
            }
        }
        int s = 0;
        for(int i = 0; i<n; i++)
        {
            // cout<<arr[i]<<" "<<m[arr[i]]<<"\n";
            s = (s + m[arr[i]])%1000000007;
        }
        return s;
    }
};