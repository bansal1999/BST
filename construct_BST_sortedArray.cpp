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


BinaryTreeNode<int>* abc(int *a,int s,int e){
  if(s>e)
    return NULL;
  int m=(s+e)/2;
  BinaryTreeNode<int>* root=new BinaryTreeNode<int>(a[m]);
  root->left=abc(a,s,m-1);
  root->right=abc(a,m+1,e);
  return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
return abc(input,0,n-1);
}


