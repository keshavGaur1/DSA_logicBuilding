/*Complete the function below

struct Node {
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
  void inOreder(Node *root,  vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        inOreder(root->left,ans);
        ans.push_back(root->data);
        inOreder(root->right,ans);
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        vector<int>ans;
        inOreder(root,ans);
        if(k > ans.size())
        {
            return -1;
        }
        // for(int i=0; i<ans.size(); i++)
        // {
            
        // }
        return ans[k-1];
    }
};
