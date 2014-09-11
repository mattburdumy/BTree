//
//  BinarySearchTree.h
//  Binary Search Tree
//
//  Created by Matt Burdumy on 10/21/12.
//  Copyright 2012 Georgetown University. All rights reserved.
//

#ifndef Binary_Search_Tree_BinarySearchTree_h
#define Binary_Search_Tree_BinarySearchTree_h
using namespace std;

struct simpleNode
{
    int data;
    simpleNode *left;
    simpleNode *right;
    ~simpleNode();
};

simpleNode::~simpleNode() // Destructor for simple node.
{
    delete this;
}


template <typename TreeType>
class BinaryTree
{
private: 
    Bnode<TreeType> * root;
    int nodeCount;
    void insert_helper(TreeType &this_root, int &input);
    void PIO_helper(TreeType &this_root);
    void post_order_helper(TreeType &this_root);
    void pre_order_helper(TreeType &this_root);
    bool find_helper(TreeType &this_root, int find_me);
    void delete_helper(TreeType * &this_root);
public:
    explicit BinaryTree(); // Default Constructor
    void insert( TreeType &input); // Inserts into the tree
    void printInOrder();// Prints BST In order
    void printPostOrder();// Prints in post order.
    void printPreOrder(); // Prints in pre order.
    int getNodeCount();
    bool find(TreeType find_me);
    void delete_all(); // Clears the whole tree, including root.
    ~BinaryTree(); // Destructor
};

template <typename TreeType>
BinaryTree<TreeType>::BinaryTree()
{
    nodeCount= 0;
    root = new TreeType;
    root->data = NULL;
    root->left = NULL;
    root->right = NULL;
}

template <typename TreeType>
void BinaryTree<TreeType>::insert(TreeType &input)
{
    if(nodeCount == 0)
    {
        root = new TreeType;
        root->data = input;
        root->left = NULL;
        root->right = NULL;
        nodeCount++;
        return;
    }
    else
        insert_helper(*(this->root), input);
}

template <typename TreeType>
void BinaryTree<TreeType>::insert_helper(TreeType &this_root, int &input)
{
    if (input == this_root.data)
    {
        cout<<"Item to be inserted is equal to another node, cannot be inserted"<<endl;
        return;
    }
    if (input>this_root.data) // Check to the right
    {
        if (this_root.right == NULL) // It must go there then.
        {
            this_root.right = new simpleNode;
            this_root.right->data = input;
            this_root.right->right = NULL;
            this_root.right->left = NULL;
            nodeCount++;
            return;
        }
        else // RECURSE
            insert_helper(*(this_root.right), input);
                    
    }
    if (input<this_root.data) // Check to the left
    {
        if (this_root.left == NULL) // It must go here.
        {
            this_root.left = new TreeType;
            this_root.left->data = input;
            this_root.left->left = NULL;
            this_root.left->right=NULL;
            nodeCount++;
            return;
        }
        else
            insert_helper(*(this_root.left), input);
    }
    
}
   
template <typename TreeType>
void BinaryTree<TreeType>::printInOrder()
{
    PIO_helper(*root);
}

template <typename TreeType>
void BinaryTree<TreeType>::PIO_helper(TreeType &this_root)
{
    if (this_root.left==NULL && this_root.right == NULL) // Print node, return
    {
        cout<<this_root.data<<endl;
        return;
    }
    else if (this_root.left==NULL && this_root.right != NULL) // Print node, then recurse to right tree.
    {
        cout<<this_root.data<<endl;
        PIO_helper(*(this_root.right));
    }
    else if (this_root.left!=NULL && this_root.right == NULL) // Print left tree, then print node.
    {
        PIO_helper(*(this_root.left));
        cout<<this_root.data<<endl;
        
    }
    else // i.e. two children are present. Print left tree, then node, then right tree
    {
        PIO_helper(*(this_root.left));
        cout<<this_root.data<<endl;
        PIO_helper(*(this_root.right));
    }
    
    
}

template <typename TreeType>
void BinaryTree<TreeType>::printPostOrder()
{
    post_order_helper(*root);
}

template <typename TreeType>
void BinaryTree<TreeType>::post_order_helper(TreeType &this_root)
{
    if (this_root.right == NULL && this_root.left == NULL) // NO children == print 
    {
        cout<<this_root.data<<endl;
        return;
    }
    else if (this_root.right != NULL && this_root.left == NULL) // Only right children == print node, then right subtree
    {
        cout<<this_root.data<<endl;
        post_order_helper(*(this_root.right));
        return;
    }
    else if (this_root.right == NULL && this_root.left != NULL) // Only left children = print node, then left SUBTREE
    {
        cout<<this_root.data<<endl;
        post_order_helper(*(this_root.left));
        return;
    }
    else // i.e. two children. Print node, then call print on right tree, then left tree.
    {
        cout<<this_root.data<<endl;
        post_order_helper(*(this_root.right));
        post_order_helper(*(this_root.left));
        return;
    }
    
}

template <typename TreeType>
void BinaryTree<TreeType>::printPreOrder()
{
    pre_order_helper(*root);
}

template <typename TreeType>
void BinaryTree<TreeType>::pre_order_helper(TreeType &this_root)
{
    if (this_root.right == NULL && this_root.left == NULL) // NO children == print 
    {
        cout<<this_root.data<<endl;
        return;
    }
    else if (this_root.right != NULL && this_root.left == NULL) // Only right children == print node, then right subtree
    {
        cout<<this_root.data<<endl;
        post_order_helper(*(this_root.right));
        return;
    }
    else if (this_root.right == NULL && this_root.left != NULL) // Only left children = print node, then left SUBTREE
    {
        cout<<this_root.data<<endl;
        post_order_helper(*(this_root.left));
        return;
    }
    else // i.e. two children. Print node, then call print on left tree, then right tree.
    {
        cout<<this_root.data<<endl;
        pre_order_helper(*(this_root.left));
        pre_order_helper(*(this_root.right));
        return;
    }
    

}

template <typename TreeType>
bool BinaryTree<TreeType>::find(TreeType find_me)
{
    if (find_helper((*root), find_me))
        return true;
    else
        return false;
}

template <typename TreeType>
bool BinaryTree<TreeType>::find_helper(TreeType &this_root, int find_me)
{
    if (&this_root==NULL) // IF i have no data, find_me cannot be here
        return false;
    else if(this_root.data == find_me) // Check my node, if not...
        return true;
    else if(find_helper(*(this_root.right), find_me) || find_helper(*(this_root.left), find_me))// Check left & right
        return true;
}

template <typename TreeType>
int BinaryTree<TreeType>::getNodeCount()
{
    return nodeCount;
}

template <typename TreeType>
void BinaryTree<TreeType>::delete_all()
{
    delete_helper(root);
    nodeCount = 0;
    root = NULL;
    return;
}

template <typename TreeType>
void BinaryTree<TreeType>::delete_helper(TreeType * &this_root)
{
    if (this_root==NULL) // I Point to NUll, Nothing to delete.
        return;
    
    if (this_root->right != NULL) // Delete right sub tree, if it exists, then set right pointer to NULL
    {
        delete_helper(this_root->right);
        this_root->right = NULL;
    }
    if (this_root->left != NULL) // Then delete left subtree, if it exists
    {
        delete_helper(this_root->left);
        this_root->left = NULL;
    }
    if(this_root != NULL) // Delete me, if i exists,  then return.
    {
        this_root-> right = NULL;
        this_root-> left = NULL;
        delete this_root;
    }
    return;
    
}

template <typename TreeType>
BinaryTree<TreeType>::~BinaryTree() // TODO: Update
{
    delete_helper(root);
    
    if (root != NULL) 
        delete root;

}

#endif
