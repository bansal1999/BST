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

int lcaBinaryTree(BinaryTreeNode<int> *root, int val1, int val2)
{
    // Write your code here

    if (root == NULL)
        return NULL;
    if (root->data == val1 || root->data == val2)
    {
        return root->data;
    }
    int a = lcaBinaryTree(root->left, val1, val2);
    int b = lcaBinaryTree(root->right, val1, val2);
    if (a == NULL && b == NULL)
        return NULL;
    else if (a == NULL && b != NULL)
    {
        return b;
    }
    else if (a != NULL && b == NULL)
    {
        return a;
    }
    else
    {
        return root->data;
    }
}
