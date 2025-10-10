/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector <int> ans;
    	queue<Node*> q;
    	q.push(root);
    	bool flag=false;
    	
    	while( !q.empty())
    	{
    	    int n=q.size();
    	    vector<int> v(n);
    	    
    	    for(int i=0;i<n;i++)
    	    {
    	    Node* temp=q.front();
    	    q.pop();
    	    
    	    if(flag==false){
    	        v[i]=temp->data;
    	    }
    	    else{
    	        v[n-i-1]=temp->data;
    	    }
    	    
    	    if(temp->left != NULL){
    	        q.push(temp->left);
    	    }
    	    if(temp->right != NULL){
    	        q.push(temp->right);
    	    }
    	   }
    	    
    	    flag = !flag;
    	    for(auto j : v){
    	        ans.push_back(j);
    	    }
    	}
    	
    	return ans;
    }
};