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

#include <vector>
#include <algorithm>

void convertToArray(BinaryTreeNode<int> *root, vector<int> &output)
{
    if (root == NULL)
    {
        return;
    }
    output.push_back(root->data);
    convertToArray(root->left, output);
    convertToArray(root->right, output);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum)
{
    vector<int> output;
    convertToArray(root, output);

    sort(output.begin(), output.end());

    int i = 0, j = output.size() - 1;
    while (i < j)
    {
        if (output[i] + output[j] == sum)
        {
            // If duplicate elements are present
            int countI = 1, countJ = 1;

            // Count the number of times 1st element is present
            int k = i + 1;
            while (output[k] == output[i])
            {
                countI++;
                k++;
            }

            // Count the number of times 2nd element is present
            k = j - 1;
            while (output[k] == output[j])
            {
                countJ++;
                k--;
            }

            // Print the pair count times
            int count = countI * countJ;
            while (count > 0)
            {
                cout << output[i] << " " << output[j] << endl;
                count--;
            }
            i += countI;
            j -= countJ;
        }
        else if (output[i] + output[j] > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}