class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s1,s2;
        int n = expression.size();
        for(int i = 0; i<n; i++)
        {
            // cout<<"index : "<<i<<" "<<s2.size()<<"\n";
            if(expression[i] == '|' || expression[i] == '&' || expression[i] == '!')
            {
                s1.push(expression[i]);
            }
            else if(expression[i] == ',') continue;
            else
            {
                if(expression[i] != ')') s2.push(expression[i]);
                else
                {
                    char s = s1.top();
                    // cout<<s<<"\n";
                    s1.pop();
                    if(s == '!')
                    {
                        char c = s2.top();
                        s2.pop();
                        s2.pop();
                        if(c == 't') s2.push('f');
                        else s2.push('t');
                    }
                    else
                    {
                        if(s == '&')
                        {
                            char c = 't';
                            while(s2.top() != '(')
                            {
                                // cout<<s2.top()<<" ";
                                if(s2.top() == 'f')
                                {
                                    c = 'f';
                                }
                                s2.pop();
                            }
                            s2.pop();
                            s2.push(c);
                            // cout<<"\n"<<c<<" "<<s2.size()<<" "<<s2.top()<<"\n";
                        }
                        else if(s == '|')
                        {
                            char c = 'f';
                            while(s2.top() != '(')
                            {
                                // cout<<s2.top()<<" ";
                                if(s2.top() == 't')
                                {
                                    c = 't';
                                }
                                s2.pop();
                            }
                            s2.pop();
                            // cout<<"\n"<<c<<"\n";
                            s2.push(c);
                        }
                    }
                }
            }
        }
        return (s2.top() == 't')? true: false;
    }
};