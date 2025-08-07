class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        
        priority_queue< pair<int, pair<int,int>> > pq ;  // sum , {i,j} i->a ka index j->b ka index
        set< pair<int,int> > visited ; // {i,j}
        
        vector<int> ans ;
        
        pq.push( make_pair( a[0]+b[0] , make_pair(0,0) )) ;
        visited.insert({0,0}) ;
        
        pair<int, pair<int,int>> ele ;
        int i,j,sum;
        
        while(ans.size() < k ){
            ele = pq.top();
            pq.pop();
            
            sum=ele.first ; i=ele.second.first ; j=ele.second.second ;
            
            ans.push_back(sum);
            
            if( visited.find({i+1,j}) == visited.end() ){
                pq.push( make_pair( a[i+1]+b[j] , make_pair(i+1,j) )) ;
                visited.insert({i+1,j}) ;
            }
            
            if( visited.find({i,j+1}) == visited.end() ){
                pq.push( make_pair( a[i]+b[j+1] , make_pair(i,j+1) )) ;
                visited.insert({i,j+1}) ;
            }
            
        }
        
        return ans ;
    }
};