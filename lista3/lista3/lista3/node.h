//
//  node.h
//  lista3
//
//  Created by Jan Śnieg on 27/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef node_h
#define node_h

struct node {
    int value;
    node *next;
    
    node(int x, node *n = nullptr)
    :value(x), next(n)
    {}
};

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
    node **t1=&t;
    while(*t1)
        t1 = &((*t1)->next);
    *t1=new node(x);
}

node print_list(node *t) //rekurencyjnie
{
    if(t)
    {
        std::cout << t->value << " ";
        print_list(t->next);
    }
    return 0;
}
#endif /* node_h */
