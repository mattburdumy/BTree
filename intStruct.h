//
//  TreeObjects.h
//  Binary Search Tree
//
//  Created by Matt Burdumy on 10/21/12.
//  Copyright 2012 Georgetown University. All rights reserved.
//

#ifndef Binary_Search_Tree_TreeObjects_h
#define Binary_Search_Tree_TreeObjects_h

using namespace std;

struct INT 
{
    public:
    int * data;
    INT(); // Default Constructor
    INT(int); // Constructor 
    INT(INT const &input); // Copy Constructor
    INT & operator=(INT const &rhs); // Overloading '=' operator.
    bool operator==(const INT &rhs) const;// Overloading '==' operator.
    bool operator<(const INT &rhs) const; // Overloading '<' operator.
    bool operator>(const INT &rhs) const; // Overloading '>' operator.
    ~INT(); // Destructor 
    
};
///// INT type functions defined below//////////////////////////////////

INT::INT() ////Default Constructor
{
    data = new int;
}

INT::INT(INT const &input) // Copy Constructor
{
    //cout<<"Copy Constructor Called"<<endl;
    delete data;
    data = new int;
    *data = *(input.data);
}

INT::INT(int input) // Constructor
{
    data = new int;
    *data = input;
    
}

INT & INT::operator=(INT const &rhs) // Deep copy of pointers.
{
    if (data == NULL) // Must allocate new memory
    {
        data = new int;
        
    }
    (*data) = *(rhs.data);
    
    return *this;
}

bool INT::operator==(INT const &rhs) const
{
    if (data==NULL && rhs.data == NULL) // Both are null
        return true;
    else if ( *data == *(rhs.data)) // They are equal return true.
        return true;
    else                            // They must not be equal
        return false;
}

bool INT::operator<(INT const &rhs) const
{
    if (*data < *(rhs.data))
        return true;
    else
        return false;
}

bool INT::operator>(INT const &rhs) const
{
    if (*data > *(rhs.data)) 
        return true;
    else
        return false;
}

INT::~INT() // Destructor
{
    //std::cout<<"Destructor Called"<<endl;
    if (data == NULL) {} // do nothing
    else
        delete data;
}


#endif
