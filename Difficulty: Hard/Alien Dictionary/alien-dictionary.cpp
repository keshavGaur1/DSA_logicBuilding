class Solution {
  public:
    string findOrder(vector<string> &words) {
        // finding total number of characters
        unordered_set<char> st;
        for(int i=0;i<words.size();i++){
            for(auto it : words[i] ){
                st.insert(it);
            }
        }
        
        int totalChar = st.size();
        
        // make graph
        vector<int> adj[26];
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            
            bool found = false ; // to check any ordering of characters are found or not
            
            int minLen = min(s1.size(),s2.size());
            for(int ptr=0;ptr<minLen;ptr++){
                if( s1[ptr] != s2[ptr] ){
                    int u = s1[ptr]-'a';
                    int v = s2[ptr]-'a';
                    
                    adj[u].push_back(v);
                    found=true ;
                    break ; 
                }
            }
            
            if( !found && s1.size()>s2.size() ) return "";
        }
        
        //  now topo sort
        int V=26;
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i] ){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            // node should present in graph than having in degree 0
            if( inDegree[i] == 0 && st.count(i+'a')>0 ){
                q.push(i);
            }
        }
        
        vector<int> ans ;
        while( !q.empty() ){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            
            // ab iss node ko graph se bhi htana h ,
            // to iske sabhi neighbour ki in degree 1 se kam ho jayegi
            for(auto it: adj[node]){
                inDegree[it]--;
                if( inDegree[it]==0 ){
                    q.push(it);
                }    
            }
        }
        
        if( ans.size() < totalChar ) return "";
        
        // now ans vector containing the answer of topo sort - means correct ordering
        // but we have to return a string
        string ans_str = "";
        for(auto i:ans ){
            ans_str = ans_str + char(i+'a');
        }
        
        return ans_str;
    }
};