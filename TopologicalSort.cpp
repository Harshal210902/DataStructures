vector<int> toposort(vector<int> adj[], vector<int> &indegree)
    {
        queue<int> q;
        for(int i =0;i<indegree.size();i++) if(indegree[i]==0) q.push(i);
        vector<int> ans;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto it: adj[u])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ans.size()!=indegree.size()) return {};
        return ans;
    }
