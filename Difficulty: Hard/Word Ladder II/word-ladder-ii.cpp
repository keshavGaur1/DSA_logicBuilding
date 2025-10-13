// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue< vector<string> > q;
        vector<string> usedOnLevel ;
        vector<vector<string>> ans ;
        
        // initially
        int level=0;
        q.push( {beginWord} );
        usedOnLevel.push_back( beginWord );
        
        while( !q.empty() ){
            vector<string> paths = q.front();
            q.pop();
            
            // erase all words that has been used in previous levels to transform 
            if( level < paths.size() ){
                level++;
                for(auto it : usedOnLevel ){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            
            string str = paths.back();
            if( str == endWord ){
                if( ans.size() == 0 ) {
                    ans.push_back(paths);
                }
                else if( ans[0].size() == paths.size() ){
                    ans.push_back(paths);
                }
            }
            
            for(int i=0;i<str.size();i++){
                char prevChar = str[i]; // h

                for(char ch='a';ch<='z';ch++){
                    str[i] = ch; // ait bit cit ......
                    // string present in a set
                    if( st.find(str) != st.end() ){
                        paths.push_back(str);
                        q.push(paths);
                        paths.pop_back();
                        
                        usedOnLevel.push_back(str);
                    }
                }

                str[i] = prevChar ;  // again hit for next iteration
            }
        }
        
        return ans;
    }
};