//
//  Bnode.h
//  Binary Search Tree
//
//  Created by Matt Burdumy on 10/21/12.
//  Copyright 2012 Georgetown University. All rights reserved.
//

#ifndef Binary_Search_Tree_Bnode_h
#define Binary_Search_Tree_Bnode_h

using namespace std;

template <typename T>
class Bnode
{
public:
    T *node;
    Bnode<T> *left;
    Bnode<T> *right;
    Bnode(); // default constructor
    Bnode(T const &input); // Constructor
    Bnode(Bnode const &input); // copy constructor
    ~Bnode(); // destructor
    Bnode operator=(Bnode<T> const &rhs);
    bool operator>(Bnode<T> const &rhs) const;
    bool operator<(Bnode<T> const &rhs) const;
    bool operator==(Bnode<T> const &rhs) const;
};

template <typename T>
Bnode<T>::Bnode(): node(NULL), left(NULL), right(NULL) {} // Default constructor : Should this allocate memory??

template <typename T>
Bnode<T>::Bnode(T const &input)
{
    node = new T;
    *(node->data) = *(input.data);
    left = NULL;
    right = NULL;
}

template <typename T>
Bnode<T>::Bnode(Bnode<T> const &input)
{
    node = new T;
    *node = *(input.node);
    left = input.left;
    right = input.right;
}

template <typename T>
Bnode<T>::~Bnode()
{
    delete node;
}

template <typename T>
Bnode<T> Bnode<T>::operator=(const Bnode<T> &rhs )
{
    if (node==NULL) // Must allocate memory 
    {
        node = new T;
        *node = *(rhs.node);
        right = rhs.right;
        left = rhs.left;
        
    }
    else // Bnode currently has data, must be deleted!
    {
        delete node;
        node = new T;
        *node = *(rhs.node);
        right = rhs.right;
        left = rhs.left;
    }
    
}

template <typename T>
bool Bnode<T>::operator<(const Bnode<T> &rhs) const
{
    if(*node < *(rhs.node))
        return true;
    else
        return false;
}
template <typename T>
bool Bnode<T>::operator>(const Bnode<T> &rhs) const
{
    if(*node > *(rhs.node))
        return true;
    else
        return false;
}

template <typename T>
bool Bnode<T>::operator==(const Bnode<T> &rhs) const
{
    if (node == NULL && *(rhs.node)==NULL) // Both are NULL
    {
        cout<<"Warning comparing two NULL pointers"<<endl;
        return true;
    }
    else if(node == *(rhs.node))
        return true;
    else
        return false;
}


#endif
