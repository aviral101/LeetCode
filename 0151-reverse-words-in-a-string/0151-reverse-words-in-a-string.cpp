class Solution {
public:
    string reverseWords(string str) {
       int n = str.size();
        string st = "";
        vector<string> v;
        for(int i = 0; i<n; i++)
        {
            if(str[i] == ' ')
            {
                if(st != "")
                {
                    v.push_back(st);
                    st = "";
                }
            } else {
                st = st + str[i];
            }
        }
        if(st != "") v.push_back(st);
        st = "";
        for(int i = v.size() - 1; i>=0; i--)
        {
            st = st + v[i];
            if(i!=0)
                st += ' ';
        }
        return st; 
        }
};