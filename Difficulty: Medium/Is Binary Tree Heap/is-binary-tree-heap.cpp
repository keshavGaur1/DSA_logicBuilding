// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  private:
    int countNodes(Node* root){
        if(!root) return 0;
        
        return 1+countNodes(root->left)+countNodes(root->right) ;
    }
    
    bool isCBT(Node* root,int index,int size){
        if( !root ) return true ;
        
        if( index >= size ) return false;
        
        if( root->left ){
            if( ! isCBT(root->left,2*index+1,size) ) return false ;
        }
        
        if( root->right ){
            if( ! isCBT(root->right,2*index+2,size) ) return false ;
        }
        
        return true ;
    }
    
    bool checkHeap(Node* root) {
        if( !root ) return true ;
        
        if( root->left ) {
            if(root->data < root->left->data) return false ;
        }
        
        if( root->right ) {
            if(root->data < root->right->data) return false ;
        }
        
        return checkHeap(root->left) && checkHeap(root->right) ;
    }
  public:
    bool isHeap(Node* tree) {
        // code here
        int nodes=countNodes(tree);
        
        if ( ! isCBT(tree,0,nodes) ) return false ;
        
        bool ans = checkHeap(tree);
        
        return ans;
    }
};