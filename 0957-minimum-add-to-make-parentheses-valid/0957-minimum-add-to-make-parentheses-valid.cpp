class Solution {
public:
    int minAddToMakeValid(string st) {
        stack<char> s;
        int n = st.size();
        int u = 0;
        for(int i = 0; i<n; i++)
        {
            if(st[i] == '(')
                s.push(st[i]);
            else if(st[i] == ')')
            {
                if(s.size() == 0) u++;
                else    s.pop();
            }
        }
        return u + s.size();
    }
};