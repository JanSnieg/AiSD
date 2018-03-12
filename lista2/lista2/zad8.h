//
//  zad8.h
//  lista2
//
//  Created by Jan Śnieg on 12/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad8_h
#define zad8_h
#include <random>


void zadanie8()
{
    std::cout << "\n\n___ZADANIE 8___" << std::endl;
    nodeBST *L = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
    {
        int r = generate(gen);
        insertBST(L, i);
        std::cout << r << " ";
    }
    std::cout << "\nWysokość to: " << hBST(L) << std::endl;
}
#endif /* zad8_h */
