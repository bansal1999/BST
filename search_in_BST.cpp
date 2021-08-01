// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    
    
    BinaryTreeNode<int>* ans= NULL;
    
    if(root==NULL)
        return 0;
    
    if(root->data==k)
        return root;
    
    if(root->data>k)
        ans=searchInBST(root->left,k);
    
    else
        ans=searchInBST(root->right,k);
    
    return ans;


}
