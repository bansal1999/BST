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
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root==NULL)
        return;
    
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    if(root->left==NULL){
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
        root->left = newNode;
        return;
    }
    if(root->left!=NULL){
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);
        newNode->left = root->left;
        root->left = newNode;
        return;
    }
}