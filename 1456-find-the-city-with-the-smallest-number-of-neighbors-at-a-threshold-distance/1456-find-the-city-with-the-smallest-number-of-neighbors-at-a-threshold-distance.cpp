class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int diag=0;diag<n;diag++) dist[diag][diag]=0 ;

        // floyd warshal 
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    
                    if( dist[i][k]==INT_MAX || dist[k][j]==INT_MAX ) continue ;

                    dist[i][j] = min(dist[i][j] , dist[i][k]+dist[k][j] );

                }
            }
        }

        int minCities = n; // min no. of cities which can be reached (initlally all cities)
        int cityNode = -1;

        for(int i=0;i<n;i++){
            int cnt=0; // no of cities we can reach through this city 
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold ) cnt++;
            }

            if( cnt <= minCities ){
                minCities=cnt;
                cityNode=i;
            }
        }
        return cityNode;
    }
};