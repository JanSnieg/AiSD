//
//  zad5.hpp
//  lista8
//
//  Created by Jan Śnieg on 22/05/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad5_hpp
#define zad5_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

bool ruch(int** tab, const int& tab_size, int wariant, int x, int y, int& pos_x, int& pos_y)
{
    switch (wariant) {
        case 1:
            pos_x = x + 1;
            pos_y = y - 2;
            break;
        case 2:
            pos_x = x + 2;
            pos_y = y - 1;
            break;
        case 3:
            pos_x = x + 2;
            pos_y = y + 1;
            break;
        case 4:
            pos_x = x + 1;
            pos_y = y + 2;
            break;
        case 5:
            pos_x = x - 1;
            pos_y = y + 2;
            break;
        case 6:
            pos_x = x - 2;
            pos_y = y + 1;
            break;
        case 7:
            pos_x = x - 2;
            pos_y = y - 1;
            break;
        case 8:
            pos_x = x - 1;
            pos_y = y - 2;
            break;
    }
    if (0 <= pos_x && pos_x < tab_size
        && 0 <= pos_y && pos_y < tab_size
        && tab[pos_x][pos_y] == 0)
        return true;
    return false;
}

bool skoczek(int** tab, const int& tab_size, int x, int y, int ktory)
{
    int pos_x, pos_y, wariant;
    
    tab[x][y] = ktory;
    
    if (ktory == tab_size * tab_size)
    {
        for (int i = 0; i<tab_size; i++)
        {
            for (int j = 0; j<tab_size; j++)
                cout << tab[i][j] << "\t";
            cout << endl;
        }
        return 1;
    }
    else
    {
        for (wariant = 1; wariant<9; wariant++)
            if (ruch(tab, tab_size, wariant, x, y, pos_x, pos_y) == true)
                if (skoczek(tab, tab_size, pos_x, pos_y, ktory + 1) == true)
                    return true;
        tab[x][y] = 0;
    }
    
    return false;
}

void clearTab(int** tab, const int& tab_size)
{
    for (int i = 0; i<tab_size; i++)
        for (int j = 0; j<tab_size; j++)
            tab[i][j] = 0;
}
#endif /* zad5_hpp */
