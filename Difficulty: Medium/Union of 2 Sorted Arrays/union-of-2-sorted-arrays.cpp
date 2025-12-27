class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
          int p=0;
        int q=0;
        int prev = INT_MIN;
        vector<int> union_array;
        while(p<a.size() && q<b.size() ){
            if(a[p]==b[q]){
                if(prev!=a[p]){
                    union_array.push_back(a[p]);
                }
                prev = a[p];
                p++;
                q++;
            } else if(a[p]>b[q]){
                if(prev!=b[q]){
                    union_array.push_back(b[q]);
                }
                
                prev = b[q];
                q++;
            } else if(a[p]<b[q]){
                if(prev!=a[p]){
                    union_array.push_back(a[p]);
                }
                prev = a[p];
                p++;
            }
        }
        while(p<a.size() ){
           if(prev!=a[p]){
                union_array.push_back(a[p]);
            }
            prev = a[p];
            p++;
        }
        while(q<b.size()){
            if(prev!=b[q]){
                union_array.push_back(b[q]);
            }
            prev = b[q];
            q++;
        }
        return union_array;
    }
};