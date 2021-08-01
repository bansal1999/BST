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

int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
	 if(root==NULL)
        return 0;
    if(root->data==val1 || root->data==val2)
        return root->data;
    int a=0,b=0;
    if(val1<root->data && val2<root->data){
        return lcaInBST(root->left,val1,val2);
    }
    else if(val1>root->data && val2>root->data){
        return lcaInBST(root->right,val1,val2);
    }
    else{
        a=lcaInBST(root->left,val1,val2);
        b=lcaInBST(root->right,val1,val2);
        if(a==0 && b==0)
            return NULL;
        else if(a==0 && b!=0)
            return b;
        else if(a!=0 && b==0)
            return a;
        else
            return root->data;
    }
}
