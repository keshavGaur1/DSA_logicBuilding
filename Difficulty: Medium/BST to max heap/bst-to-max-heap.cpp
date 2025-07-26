// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  private:
    void inorder(Node* root,vector<int>& sortedArr){
        if( !root ) return ;
        
        inorder(root->left,sortedArr);
        sortedArr.push_back(root->data);
        inorder(root->right,sortedArr);
    }
    
    void postorderFill(Node* root,vector<int>& sortedArr){
        if( !root ) return ;
        
        postorderFill(root->left,sortedArr);
        postorderFill(root->right,sortedArr);
        
        root->data = sortedArr[i];
        i++;
    }
  public:
    int i=0;
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> sortedArr ;
        inorder(root,sortedArr);
        
        postorderFill(root,sortedArr);
    }
};
