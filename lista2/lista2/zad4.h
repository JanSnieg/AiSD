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
    std::cout << "\n\n___ZADANIE 4___" << std::endl;
    int n = 20; //wielkosc tablicy
    int k = 10; //ile przesuwamy w prawo
    int t[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int j = n-k;
    std::vector<int> zmienne;
    for (auto i=0; i<j; i++)
    {
        zmienne.push_back(t[i]);
    }
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
        std::cout << t[i] << " ";
    }
}

void zadanie4_2(int n, int a[], int k)
{
    std::cout << "\n\n___ZADANIE 4_2___" << std::endl;
    int temp = a[0];
    for (auto i=0; i<n; i++)
        a[((i+1)*k)%n] = a[(i*k)%n];
    a[((n-1)*k)%n] = temp;
    for (auto i=0; i<n; i++)
        std::cout << a[i] << " ";
}

#endif /* zad4_h */
