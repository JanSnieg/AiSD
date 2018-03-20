//
//  zad14.h
//  lista2
//
//  Created by Jan Śnieg on 20/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad14_h
#define zad14_h

void inorder_do_notRec(node3 *t, void f(node3* x))
{
    node3 *prev = nullptr;
    while (t)
    {
        if (prev == t->parent)
        {
            if (t->left)
            {
                prev = t;
                t = t->left;
                continue;
            }
            else
                prev = nullptr;
        }
        else if (prev == t->left)
        {
            f(t);
            if (t->right)
            {
                prev = t;
                t = t->right;
                continue;
            }
            else
                prev = nullptr;
        }
        else if (prev == t->right)
        {
            prev = t;
            t = t->parent;
        }
    }
}
void f(node3 *t)
{
    t->x *= 10;
}

void zadanie14()
{
    std::cout << "\n\n___ZADANIE 14___" << std::endl;
    node3 *t = new node3(0);
    
    insert3(t, 3);
    insert3(t, 4);
    insert3(t, 1);
    insert3(t, 7);
    insert3(t, -4);
    insert3(t, 9);
    insert3(t, 2);
    
    inorder3(t);
    std::cout << std::endl;
    
    inorder_do(t, f);
    inorder3(t);
    std::cout << std::endl;
    
    inorder_do_notRec(t, f);
    inorder3(t);
    std::cout << std::endl;
}
#endif /* zad14_h */
