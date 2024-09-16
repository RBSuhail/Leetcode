class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int>{0};
        if(n==2) return edges[0];

        vector<vector<int>> adjList(n);

        vector<int> inDegree(n,0);
        for(int i=0;i<edges.size();++i){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
        }

        queue<int> bfs;
        for(int i=0;i<inDegree.size();++i){
            if(inDegree[i]==1){
                bfs.push(i);
                inDegree[i]--;
            }
        }

        vector<int> v;
        while(!bfs.empty()){
            int s=bfs.size();
            
            while(s){
                int front=bfs.front();
                bfs.pop();
                for(int i=0;i<adjList[front].size();++i){
                    inDegree[adjList[front][i]]--;
                    if(inDegree[adjList[front][i]]==1){
                        bfs.push(adjList[front][i]);
                    }
                }
                --s;
            }
            if(bfs.size()<=2 && bfs.size()>=1){
                v.clear();
                int size=bfs.size();
                while(size)
                {
                    int e=bfs.front();
                    v.push_back(e);
                    bfs.pop();
                    bfs.push(e);
                    --size;
                }
            }
        }

        return v;
    }
};





