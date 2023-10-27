class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> ined(numCourses,0);
        for(int i = 0; i<n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ined[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++)
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
        for(int i = 0; i<numCourses; i++)
        {
            if(ined[i] != 0) return false;
        }
        return true;
    }
};