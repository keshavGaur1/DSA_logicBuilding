class disjointSet
{
private:
    vector<int> parent, rank , size;

public:
    disjointSet(int n)
    {
        // 1 based indexing (also works for 0 based indexing)
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        parent.resize(n + 1);

        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        // node aur uska parent same h , to whi parent h
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulPar_u = findParent(u);
        int ulPar_v = findParent(v);

        // agar u & v ke ultimate parent same hi h , to wo (u,v) phele se ek hi componant mai hai. No need to do anything in disjoint set D.S.
        if (ulPar_u == ulPar_v)
            return;

        if (size[ulPar_u] < size[ulPar_v])
        { // u ka size chota h , to connect u to v
            parent[ulPar_u] = ulPar_v;
            size[ulPar_v] += size[ulPar_u];
        }
        else
        { // v ka size chota h , to connect v to u
            parent[ulPar_v] = ulPar_u;
            size[ulPar_u] += size[ulPar_v];
        }
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector< pair<int, pair<int,int> >> adj(V);
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            
            adj.push_back( {wt,{u,v}} );
        }
        
        sort(adj.begin(),adj.end());
        
        disjointSet ds(V);
        int MSTsum=0;
        
        for(auto i:adj){
            int wt=i.first;
            int u=i.second.first;
            int v=i.second.second;
            
            if( ds.findParent(u) != ds.findParent(v) ){
                MSTsum+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return MSTsum;
    }
};