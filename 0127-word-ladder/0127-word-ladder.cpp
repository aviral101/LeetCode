class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> m;
        int n = wordList.size();
        vector<vector<int>> adj(n);
        m[beginWord] = 0;
        for(int i = 0; i<n; i++)
        {
            m[wordList[i]] = i;
        }
        for(int k = 0; k<n; k++)
        {
            for(int i = 0; i<wordList[k].size(); i++)
            {
                string x = wordList[k];
                for(int j = 'a'; j<= 'z'; j++)
                {
                    if(j != wordList[k][i])
                    {
                        x[i] = j;
                        if(m.find(x) != m.end() )
                        {
                            adj[k].push_back(m[x]);
                        }
                    }
                }
            }
        }   
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++)
        {

            int c = 0;
            for(int k = 0; k<wordList[i].size(); k++)
            {
                if(wordList[i][k] != beginWord[k]) c++;
            }
            if(c == 1)
            {
                q.push({i,1});
            }
        }
        vector<int> visited(n,0);
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            if(wordList[p.first] == endWord) return p.second + 1;
            for(auto i : adj[p.first])
            {
                if(!visited[i])
                {

                    visited[i] = 1;
                    q.push({i,p.second + 1});
                }
            }
        }
        return 0;
    }
};