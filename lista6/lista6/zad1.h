//
//  zad1.h
//  lista6
//
//  Created by Jan Śnieg on 16/04/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad1_h
#define zad1_h
#include <string>
#define A 63689;
//SipHash
int h(std::string s)
{
    unsigned int hash = 1315423911;
    for(std::size_t i = 0; i < s.length(); i++)
        hash ^= ((hash << 5) + s[i] + (hash >> 2));
    return (hash & 0x7FFFFFFF);
}

void zadanie1()
{
    std::string tekst = "ala ma kota";
    std::cout << tekst << ": " << h(tekst) << std::endl;
}

#endif /* zad1_h */
