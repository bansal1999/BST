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
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int a = height(root->left);
    int b = height(root->right);
    if (a >= b)
        return a + 1;
    else
        return b + 1;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 1;
    int h = height(root);
    int a = largestBSTSubtree(root->left);
    int b = largestBSTSubtree(root->right);
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else if (a == b && a == h - 1 && root->left != NULL && root->right != NULL && root->left->data < root->data && root->right->data >= root->data)
        return a + 1;
    else if (a == b)
        return a;
}