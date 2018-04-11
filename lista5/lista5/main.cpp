//
//  main.cpp
//  lista5
//
//  Created by Jan Śnieg on 10/04/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#include <iostream>
#include "sorty.h"

int main(int argc, const char * argv[]) {
    int t1[] = {1,2,3,4,5,6,7};
    int t2[] = {7,6,5,4,3,2,1};
    insertion_sort(t1, 7);
    insertion_sort(t2, 7);
    return 0;
}
