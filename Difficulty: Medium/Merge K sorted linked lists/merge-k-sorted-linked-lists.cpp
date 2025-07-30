/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  
  class Compare{
      public:
      bool operator() (Node* a , Node* b){
          return a->data > b->data ;
      }
  };
  
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node* , vector<Node*> , Compare > minH(arr.begin(),arr.end());
        
        Node* dummy = new Node(-1);
        Node* ele ;
        Node* tail=dummy ;
        
        while( !minH.empty() ){
           ele = minH.top();
           minH.pop();
           
           if( ele->next ){
               minH.push(ele->next);
           }
           
           tail->next = ele ;
           tail=tail->next ;
        }
        
        tail->next = NULL ;
        
        return dummy->next;
    }
};