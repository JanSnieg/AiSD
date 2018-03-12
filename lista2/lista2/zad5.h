//
//  zad5.h
//  lista2
//
//  Created by Jan Śnieg on 12/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

struct lnode  // drzewo bez wskaźnika na rodzica
{
    int x;
    lnode* next;
    
    lnode(int x0, lnode* n=nullptr)
    :x(x0), next(n)
    {}
};

void insert(lnode *& t, int x) // wstawianie (nierekurencyjna)
{
    lnode **t1=&t;
    while(*t1)
        t1 = &((*t1)->next);
    *t1=new lnode(x);
}

void inorder(lnode *t)  // wypisanie kluczy w porządku "in order"
{
    if(t)
    {
        inorder(t->next);
        std::cout<<t->x<<" ";
    }
}

void reverse(lnode *&L)
{
    lnode *preview = NULL;
    lnode *current = L;
    lnode *next = NULL;
    while (current)
    {
        next = current->next;
        current->next = preview;
        preview = current;
        current = next;
    }
    L = preview;
}

void marge(lnode *&L1, lnode *&L2)
{
    
}

void zadanie5()
{
    std::cout << "\n\n___ZADANIE 5___" << std::endl;
    lnode * t = nullptr;
    for (auto i=0; i<10; i++)
        insert(t, i);
    
    std::cout << "In order: " << std::endl;
    inorder(t);
    std::cout << std::endl;
    std::cout << "Reversed: " << std:: endl;
    reverse(t);
    inorder(t);
}


