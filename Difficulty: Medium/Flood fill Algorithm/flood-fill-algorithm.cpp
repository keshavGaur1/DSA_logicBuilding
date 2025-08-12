class Solution {
  private:
    void traverse(vector<vector<int>>& image, int sr, int sc,
                                  int newColor,int prevColor,vector<vector<int>>& visited,vector<vector<int>>& ans){
        int n=image.size() , m=image[0].size() ;
        visited[sr][sc]=1;
        ans[sr][sc]=newColor;
        
        int rowArr[]={-1,0,+1,0};
        int colArr[]={0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int newR = sr+rowArr[i];
            int newC = sc+colArr[i];
            
            if( newR>=0 && newR<n && newC>=0 && newC<m && visited[newR][newC]==0 && image[newR][newC]==prevColor ){
                traverse(image,newR,newC,newColor,prevColor,visited,ans); 
            }
        }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n=image.size() , m=image[0].size() ;
        vector<vector<int>> ans=image;
        vector<vector<int>> visited(n,vector<int> (m,0));
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         ans[i][j] = image[i][j];
        //     }
        // }
        
        traverse(image,sr,sc,newColor,image[sr][sc],visited,ans); 
        
        return ans ;
    }
};