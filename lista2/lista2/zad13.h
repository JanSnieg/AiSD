//
//  zad13.h
//  lista2
//
//  Created by Jan Śnieg on 20/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef Header_h
#define Header_h

void inorder_do(node3 *t, void f(node3* x))
{
    if(t)
    {
        inorder_do(t->left, f);
        f(t);
        inorder_do(t->right, f);
    }
}

#endif /* Header_h */
