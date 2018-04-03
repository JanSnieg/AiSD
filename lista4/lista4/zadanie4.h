//
//  zadanie4.h
//  lista4
//
//  Created by Jan Śnieg on 03/04/2018.
//  Copyright © 2018 Jan Śnieg. All rights reserved.
//

#ifndef zadanie4_h
#define zadanie4_h

int partition (int n, double t[])
{
    int k = -1;
    int ile = n;
    double x = t[n / 2];
    while (true)
    {
        while (t[--n] > x);
        while (t[++k] < x);
        if (n > k)
        {
            double y = t[k];
            t[k] = t[n];
            t[n] = y;
        }
        else
            return k;
    }
}

// sortowanie szybkie
void quick_sort (int n, double t[])
{
    if (n > 1)
    {
        int k = partition (n, t);    //podziel na dwie czesci
        quick_sort (k, t);    //posortuj lewa
        quick_sort (n - k, t + k);    //posortuj prawa
    }
}

#endif /* zadanie4_h */
