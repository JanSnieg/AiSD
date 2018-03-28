//
//  zadanie7.h
//  lista3
//
//  Created by Jan Śnieg on 28/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zadanie7_h
#define zadanie7_h

int find_level(Node *root, double v)
{
    Node *n = root;
    int level = 1;
    while (n && n->x != v)
    {
        level++;
        if (v < n->x)
            n = n->left;
        else n = n->right;
    }
    return n ? level : 0;
}

void zadanie7()
{
    Node *root = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{1,100};
    int liczba = 0;
    int los = generate(gen);
    for (auto i=0; i<10; i++)
    {
        int r = generate(gen);
        if (i == los/10)
            liczba = r;
        insert_recursive(root, r);
        std::cout << r << " ";
    }
    std::cout << "\nZADANIE 7:";
    std::cout << "\nLiczba: " << liczba << " Poziom: " << find_level(root, liczba) << std::endl;
}

#endif /* zadanie7_h */
