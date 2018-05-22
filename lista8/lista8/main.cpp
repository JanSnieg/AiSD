//
//  main.cpp
//  lista8
//
//  Created by Jan Śnieg on 22/05/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#include <iostream>
#include "zad5.hpp"

int main(int argc, const char * argv[]) {
    int max;
    cout << "Podaj rozmiar:\t";
    cin >> max;
    int** tab = new int*[max];
    for (int i = 0; i<max; i++)
        tab[i] = new int[max];
    
    for (int i = 0; i<max; i++)
        for (int j = 0; j<max; j++)
        {
            clearTab(tab, max);
            cout << "\n(i, j)=\t(" << i << ", " << j << ")\n";
            skoczek(tab, max, i, j, 1);
        }
    
    
    getchar();
    return 0;
}
