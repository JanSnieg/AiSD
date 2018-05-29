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
    // tworzenie szchownicy o rozmiarze max x max
    int** tab = new int*[max];
    for (int i = 0; i<max; i++)
        tab[i] = new int[max];
    
    int start_x, start_y;
    cout << "Wpisz pole startowe (x,y) (od 0 do rozmiaru ktory wpisales -1)\t";
    cin >> start_x>> start_y;
    
    clearTab(tab, max);
    cout << "\n(" << start_x << ", " << start_y << ")\n";
    skoczek(tab, max, start_x, start_y, 1);
    
    
    cout << "Koniec!";
    
    // czyszczenie pamieci
    for (int i = 0; i < max; i++) {
        delete[] tab[i];
    }
    delete[] tab;
    
    
    std::cin.get();
    std::cin.get();
    return 0;
}

