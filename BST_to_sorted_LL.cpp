// Following is the Binary Tree node structure
/**************
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
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
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL){
        Node<int>* output = new Node<int>(root->data);
        return output;
    }
    Node<int>* output = new Node<int>(root->data);
    Node<int>* leftOutput = constructLinkedList(root->left);
    Node<int>* rightOutput = constructLinkedList(root->right);
    if(leftOutput!=NULL){
        Node<int>* temp = leftOutput;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=output;
    }
    output->next = rightOutput;
    if(leftOutput==NULL)
        return output;
    return leftOutput;
    
}