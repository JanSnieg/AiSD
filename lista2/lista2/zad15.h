//
//  zad15.h
//  lista2
//
//  Created by Jan Śnieg on 20/03/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zad15_h
#define zad15_h

int height(nodeBST*t)
{
    if(t)
    {
        int lHeight = height(t->left);
        int rHeight = height(t->right);
        
        if(lHeight > rHeight)
            return lHeight+1;
        else
            return rHeight+1;
    }
    else
        return 0;
}


void zadanie15()
{
    std::cout << "\n\n___ZADANIE 15___" << std::endl;
    nodeBST *L = nullptr;
    std::mt19937 gen{std::random_device{}()};
    std::uniform_int_distribution<int> generate{0,100};
    for (auto i=0; i<10; i++)
    {
        int r = generate(gen);
        insertBST(L, r);
        std::cout << r << " ";
    }
    std::cout << "\nHeight of tree is: " << height(L) << std::endl;
    std::cout << "Complexity: O(n)" << std::endl;
}
#endif /* zad15_h */
