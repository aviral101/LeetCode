class Solution {
public:
    int repeatedStringMatch(string text, string b) {
        int n = b.size();
        int m = text.size();
        int a = 0;
        int x = (n > m)? n : m;
        for(int i = 0; i<n; i++)
        {
            a += (b[i] - 'a' + 1);
        }	
        int c = 0;
        int l = 0;
        for(int i =0; i<3*x; i++)
        {
            c += (text[i%m] - 'a' + 1);
            if(i >= b.size() - 1)
            {
                if(a == c)
                {
                    int r = 0;
                    int flag = 0;
                    for(int k = l; k<=i; k++)
                    {
                        if(text[k%m] != b[r++])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0)
                    {
                        if((i + 1) % m == 0) return (i+1)/m;
                        else return (i+1)/m + 1;
                    }
                }
                c -= (text[l%m] - 'a' + 1);
                l++;
            }
        }
        return -1;
    }
};