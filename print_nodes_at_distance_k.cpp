/*
    Time complexity: O(N)
    Space complexity: O(H)

    where N is the number of nodes in the input binary tree and
    H is the height of the input binary tree
*/

void nodesAtDistanceKDown(BinaryTreeNode<int> *root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        cout << root->data << endl;
        return;
    }
    
    nodesAtDistanceKDown(root->left, k - 1);
    nodesAtDistanceKDown(root->right, k - 1);
}

int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k) {
    if (root == NULL) return -1;

    if (root->data == target) {
        nodesAtDistanceKDown(root, k);
        return 0;
    }

    int leftD = nodesAtDistanceKHelper(root->left, target, k);

    if (leftD != -1) {
        if (leftD + 1 == k) {
            cout << root->data << endl;
        } else {
            nodesAtDistanceKDown(root->right, k - leftD - 2);
        }

        return 1 + leftD;
    }

    int rightD = nodesAtDistanceKHelper(root->right, target, k);
    if (rightD != -1) {
        if (rightD + 1 == k) {
            cout << root->data << endl;
        } else {
            nodesAtDistanceKDown(root->left, k - rightD - 2);
        }

        return 1 + rightD;
    }

    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceKHelper(root, node, k);
}