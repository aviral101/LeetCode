class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        for(int i = 0; i<n-1; i++)
        {
            char c = s[0];
            string st = "";
            int t = 0;
            int j;
            for(j = 0; j<s.size(); j++)
            {
                if(s[j] != c)
                {
                    
                    st = st + (char)(t + '0');
                    st = st + c;
                    t = 1;
                    c = s[j];
                }
                else t++;
            }
            st = st + (char)(t + '0');
            st = st + s[s.size() - 1];
            // cout<<st<<"\n";
            s = st;
        }
        return s;
    }
};