class Solution {
  public:
    int leastInterval(int N, int n, vector<char> &tasks) {
        // code here
        priority_queue<int> pq;
        vector<int> mp(26,0);

        for(int i=0;i<tasks.size();i++){
            mp[ tasks[i]-'A' ] ++ ;
        }

        for(int i=0;i<26;i++){
            if( mp[i] > 0 ) {
                pq.push(mp[i]) ;
            }
        }

        int ans = 0 ;
        while( !pq.empty() ){

            vector<int> temp ;
            for(int i=0;i<n+1;i++){
                if( !pq.empty() ){  // har iteration mai check krna pdega ki pq mai ele h ya nhi 
                    int freq=pq.top();
                    pq.pop();
                    freq -- ;
                    temp.push_back(freq) ;
                }
            }

            for(int i=0;i<temp.size();i++){
                if( temp[i] > 0 ) {
                    pq.push(temp[i]); 
                }
            } 

            if( pq.empty() ){  // matlb sare task ho chuke 
                ans += temp.size() ; 
            }
            else{
                ans += n+1 ;
            }
        }
        return ans;
    
    }
};