//
//  nodeBST.h
//  lista3
//
//  Created by Jan Śnieg on 28/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef nodeBST_h
#define nodeBST_h

struct Node  // drzewo bez wskaźnika na rodzica
{ 
    int x;
    Node* left;
    Node* right;
    
    Node(int x0, Node* l=NULL, Node* r=NULL)
    :x(x0), left(l), right(r)
    {}
};

void insert_recursive(Node *& t, int x) // wstawianie (rekurenycjnie)
{
    if(!t)
        t=new Node(x);
    else
        if(x<t->x)
            insert_recursive(t->left,x); // tail recursion
        else
            insert_recursive(t->right,x); // tail recursion
}

void inorder(Node *t)  // wypisanie kluczy w porządku "in order"
{
    if(t)
    {
        inorder(t->left);
        std::cout<<t->x<<" ";
        inorder(t->right);
    }
}

#endif /* nodeBST_h */
