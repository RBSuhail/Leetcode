class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==0)return {};
        if(n==1)return {0};
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int>bfs;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)bfs.push(i);
        }

        
        while(n>2)
        {
            int sz=bfs.size();
            n-=sz;
            while(sz--)
            {
                int node=bfs.front();
                bfs.pop();
                
                for(auto it:adj[node])
                {   indegree[it]--;
                    if(indegree[it]==1)
                    {
                        bfs.push(it);
                    }
                }
            }
        }
        vector<int>result;
        while(!bfs.empty())
        {   int node=bfs.front();
            result.push_back(node);
            bfs.pop();
        }
        return result;
    }
};