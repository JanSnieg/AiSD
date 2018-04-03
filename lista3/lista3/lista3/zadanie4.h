//
//  zadanie4.h
//  lista3
//
//  Created by Jan Śnieg on 27/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zadanie4_h
#define zadanie4_h

node getMiddle (node *start)
{
    node *fast = start;
    node *slow = start;
    if(start)
    {
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return *slow;
    }
    else
        return *start;
}

node mergeTwoList(node *left, node *right)
{
    node *merged = nullptr;
    node *tmp = nullptr;
    
    node *lastAdded = nullptr;
    
    while (left && right)
    {
        if (left->value > right->value)
        {
            tmp = new node(right->value);
            right = right->next;
        }
        else
        {
            tmp = new node(left->value);
            left = left->next;
        }
        if (!merged)
            merged = tmp;
        else
            lastAdded->next = tmp;
        lastAdded=tmp;
        if (left)
            lastAdded->next = left;
        else
            lastAdded->next = right;
    }
    return *merged;
}

node mergeSortList (node *start)
{
    if(!start || !start->next)
        return *start;
    node middle = getMiddle(start);
    node *nextOfMiddle = middle.next;
    middle.next = nullptr;
    node left = mergeSortList(start);
    node right = mergeSortList(nextOfMiddle);
    
    node sorted = mergeTwoList(&left, &right);
    return sorted;
}

void zadanie4()
{
    node *L = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
        insert(L, generate(gen));
    std::cout << "\nBefore sorting:\n";
    print_list(L);
    node L_after = mergeSortList(L);
    std::cout << "\nAfter sorting:\n";
    print_list(&L_after);
}

#endif /* zadanie4_h */
