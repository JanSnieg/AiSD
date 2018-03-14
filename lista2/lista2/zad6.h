//
//  zad6.h
//  lista2
//
//  Created by Jan Śnieg on 12/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad6_h
#define zad6_h

int count6 = 0;

lnode* merge (lnode *L1, lnode *L2)
{
    if (!L1)
    {
        count6++;
        return L2;
    }
    else if (!L2)
    {
        count6++;
        return L1;
    }
    if (L1->x < L2->x)
    {
        count6++;
        L1->next = merge(L1->next, L2);
        return L1;
    }
    else
    {
        count6++;
        L2->next = merge(L1, L2->next);
        return L2;
    }
}

void zadanie6()
{
    std::cout << "\n\n___ZADANIE 6___" << std::endl;
    lnode *L1 = nullptr;
    lnode *L2 = nullptr;
    lnode *result = nullptr;
    for (auto i=0; i<10; i++)
    {
        insert(L1, i);
        insert(L2, i*5);
    }
    std::cout << "List 1: " << std::endl;
    inorder(L1);
    std::cout << "\nList 2: " << std::endl;
    inorder(L2);
    result = merge(L1, L2);
    std::cout << "\nMarged: " << std::endl;
    inorder(result);
    std::cout << "\nIlość porównań: " << count6 << std::endl;
}

#endif /* zad6_h */
