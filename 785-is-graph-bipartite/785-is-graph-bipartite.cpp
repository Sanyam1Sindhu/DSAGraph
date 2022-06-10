class Solution {
public:
    bool isbip(int s,vector<vector<int>>& graph,vector<int> color)
    {
          queue<int> q;
          q.push(s);
          color[s]=1;
		  
         while(!q.empty())
         {
            int node=q.front();
            q.pop();
            
            for(auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1+color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(!isbip(i,graph,color))
                return false;
        }
        return true;
    }
};