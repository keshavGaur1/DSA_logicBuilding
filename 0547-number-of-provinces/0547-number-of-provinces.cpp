class disjointSet
{
public:
vector<int> parent , size;
    disjointSet(int n)
    {
        // 1 based indexing (also works for 0 based indexing)
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        disjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( i!=j && isConnected[i][j]==1 ){
                    ds.unionBySize(i,j);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if( ds.parent[i]==i ) cnt++;
        }

        return cnt;
    }
};