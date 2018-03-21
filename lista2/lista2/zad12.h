//
//  zad12.h
//  lista2
//
//  Created by Jan Śnieg on 20/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad12_h
#define zad12_h

struct node3  // drzewo z wskaźnika na rodzica
{
    node3 (int v = 0, node3 *p = nullptr) :
    x(v), parent(p) {}
    
    int x;
    node3* left = nullptr;
    node3* right = nullptr;
    node3* parent = nullptr;
};

void insert3(node3 *t, int x)
{
    node3 **n = &t;
    node3 *p = nullptr;
    while(*n)
    {
        p = *n;
        if (x == (*n)->x)
            return;
        if(x < (*n)->x)
            n = &(*n)->left;
        else
            n = &(*n)->right;
    }
    *n = new node3(x, p);
}

void remove3(node3 *t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
    node3 *t1 = t;
    node3 **p = 0;
    while (t1 && t1->x != x)
    {
        if(x < t1->x)
        {
            p = &(t1->left);
            t1 = t1->left;
        }
        else
        {
            p = &(t1->right);
            t1 = t1->right;
        }
    }
    if(t1)
    {
        if (!t1->right && !t1->left)
        {
            *p = 0;
            delete t1;
            return;
        }
        else if (t1->left && !t1->right)
        {
            *p = t1->left;
            delete t1;
            return;
        }
        else if (t1->right && !t1->left)
        {
            *p = t1->right;
            delete t1;
            return;
        }
    }
    node3 * tmp = t1->left;
    if (tmp ->right)
    {
        while (tmp->right)
            tmp = tmp->right;
        t1->x = tmp->x;
        tmp->parent->right = tmp->left;
    }
    else
    {
        t1->x = tmp->x;
        t1->left = tmp->left;
    }
    delete tmp;
}

void inorder3(node3 *root)
{
    if (root)
    {
        inorder3(root->left);
        std::cout << "Node : " <<  root->x << ", ";
        if (!root->parent)
            std::cout << "Parent : NULL \n";
        else
            std::cout << "Parent :" << root->parent->x << std::endl;
        inorder3(root->right);
    }
}

void zadanie12()
{
    std::cout << "\n\n___ZADANIE 12___" << std::endl;
    int toRemove=0;
    node3 *L = new node3(0);
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
    {
        int r = generate(gen);
        insert3(L, r);
        toRemove = r;
        std::cout << r << " ";
    }
    std::cout << std::endl;
    inorder3(L);
    std::cout << "AFTER REMOVAL OF LAST ELEMENT:\n" ;
    remove3(L, toRemove);
    inorder3(L);
}

#endif /* zad12_h */
