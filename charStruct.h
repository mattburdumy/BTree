//
//  charStruct.h
//  Binary Search Tree
//
//  Created by Matt Burdumy on 10/21/12.
//  Copyright 2012 Georgetown University. All rights reserved.
//

#ifndef Binary_Search_Tree_charStruct_h
#define Binary_Search_Tree_charStruct_h
using namespace std;

struct CHAR 
{
public:
    char * data;
    CHAR(); // Default Constructor
    CHAR(char); // Constructor 
    CHAR(CHAR const &input); // Copy Constructor
    CHAR operator=(CHAR const &rhs); // Overloading '=' operator.
    bool operator==(const CHAR &rhs) const;// Overloading '==' operator.
    bool operator<(const CHAR &rhs) const; // Overloading '<' operator.
    bool operator>(const CHAR &rhs) const; // Overloading '>' operator.
    ~CHAR(); // Destructor 
};


CHAR::CHAR() ////Default Constructor
{
    data = new char;
}

CHAR::CHAR(CHAR const &input) // Copy Constructor
{
    //cout<<"Copy Constructor Called"<<endl;
    delete data;
    data = new char;
    *data = *(input.data);
}

CHAR CHAR::operator=(const CHAR &rhs)
{
    if (data == NULL) // We must allocat memory
    {
        data = new char;
        *data = *(rhs.data);
    }
    else
        *data = *(rhs.data);
    
    return *this;
}

CHAR::CHAR(char input) // Constructor
{
    data = new char;
    *data = input;
    
}

bool CHAR::operator==(CHAR const &rhs) const
{
    if (data==NULL && rhs.data == NULL) // Both are null
        return true;
    else if ( *data == *(rhs.data)) // They are equal return true.
        return true;
    else                            // They must not be equal
        return false;
}

bool CHAR::operator<(CHAR const &rhs) const
{
    if (*data < *(rhs.data))
        return true;
    else
        return false;
}

bool CHAR::operator>(CHAR const &rhs) const
{
    if (*data > *(rhs.data)) 
        return true;
    else
        return false;
}


CHAR::~CHAR()
{
    delete data;
}


#endif
