class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int &num : nums ) mp[num]++;

        vector< vector<int> > freqArr(n+1) ;

        int freq,value ;
        for(auto &it : mp ){
            value=it.first;
            freq=it.second;

            freqArr[freq].push_back(value);
        }
        
        /*
        for(int i=0;i<freqArr.size();i++){
            for(int j=0;j<freqArr[i].size();j++){
                cout<<freqArr[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        vector<int> ans ;
        
        for(int i=freqArr.size()-1; i>=1 && k ;i--){
            // vector<int> temp = freqArr[i];     // error aarhi isse kyoki temp har iteration mai copy horha
            while( freqArr[i].size() > 0 && k>0 ){
                ans.push_back( freqArr[i].back() );
                freqArr[i].pop_back();
                k--;
            }
        }

        return ans;
    }
};