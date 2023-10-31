class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>> adj(n);
        for(int i = 0; i<n; i++)
        {
            
            for(int j = i+1; j<n; j++)
            {
                int c = 0;
                for(int k = 0; k<wordList[i].size(); k++)
                {
                    if(wordList[i][k] != wordList[j][k]) c++;
                }
                if(c == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
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