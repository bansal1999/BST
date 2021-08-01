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
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, vector<int> output)
{
    if (root == NULL)
        return;
    output.push_back(root->data);
    if (k <= 0)
        return;
    if (root->left == NULL && root->right == NULL && root->data == k)
    {
        output.push_back(root->data);
        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i];
            if (i < output.size() - 1)
                cout << " ";
            i++;
        }
        cout << endl;
        return;
    }
    output.push_back(root->data);
    rootToLeafPathsSumToK(root->left, k - root->data, output);
    rootToLeafPathsSumToK(root->right, k - root->data, output);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    vector<int> output;
    rootToLeafPathsSumToK(root, k, output);
}