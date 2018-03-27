//
//  zadanie3.h
//  lista3
//
//  Created by Jan Śnieg on 27/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zadanie3_h
#define zadanie3_h

node insertion_sort (node *L)
{
    if(!L || !L->next)
        return *L;
    node *sorted = nullptr;
    while (L)
    {
        node *head = L;
        node **trail = &sorted;
        L = L->next;
        while (!(*trail == NULL || head->value < (*trail)->value))
            trail = &(*trail)->next;
        head->next = *trail;
        *trail = head;
    }
    return *sorted;
}

void zadanie3()
{
    node *L = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
    {
        insert(L, generate(gen));
    }
    std::cout << "\nBefore sorting:\n";
    print_list(L);
    node L_after = insertion_sort(L);
    std::cout << "\nAfter sorting:\n";
    print_list(&L_after);
}
#endif /* zadanie3_h */
