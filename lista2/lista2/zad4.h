//
//  zad4.h
//  lista2
//
//  Created by Jan Śnieg on 12/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//
#include <vector>

#ifndef zad4_h
#define zad4_h
void zadanie4()
{
    std::cout << "\n\n___ZADANIE 5___" << std::endl;
    int n = 16; //wielkosc tablicy
    int k = 3; //ile przesuwamy w prawo
    int t[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::vector<int> zmienne;
    for (auto i=0; i<k; i++)
    {
        zmienne.push_back(t[i]);
    }
    int j = k;
    for (auto i=0; i<n; i++)
    {
        t[i] = t[j];
        if(j == n)
        {
            for (auto m=0; m<zmienne.size(); m++)
            {
                t[i] = zmienne[m];
                i++;
            }
        }
        j++;
    }
    
    for (auto i=0; i<n; i++)
    {
        std::cout << t[i] << " " << std::endl;
    }
}


#endif /* zad4_h */
