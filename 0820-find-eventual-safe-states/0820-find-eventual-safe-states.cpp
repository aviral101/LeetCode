class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> ined(n,0);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<graph[i].size(); j++)
            {
                adj[graph[i][j]].push_back(i);
                ined[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<n; i++)
        {
            if(ined[i] == 0) q.push(i);
        }
        vector<int> v;
        while(!q.empty())
        {
            int u = q.front();
            v.push_back(u);
            q.pop();

            for(auto v : adj[u])
            {
                ined[v]--;
                if(ined[v] == 0) q.push(v);
            }
        }

        sort(v.begin(),v.end());
        return v;
    }
};