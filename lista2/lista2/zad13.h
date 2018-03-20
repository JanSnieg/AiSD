//
//  zad13.h
//  lista2
//
//  Created by Jan Śnieg on 20/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef Header_h
#define Header_h

void inorder_do(lnode *t, void f(lnode* x))
{
    if(t)
    {
        inorder_do(t->next, f);
        f(t);
        std::cout<<t->x<<" ";
    }
}

#endif /* Header_h */
